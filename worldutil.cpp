
#include "worldutil.h"

int testHashingNode(Node &n) {
    return (hash<int>()((n.point.x + n.point.y * 30)));
}

int getNodeHash(Node n) {
    return n.point.x + n.point.y * 30;
}

int getPointHash(Point p) {
    return p.x + p.y * 30;
}

bool check_key(unordered_map<Node, int, HashingNodes> dist, Node key) {
    if (debugMode != 0) {
        bool returntype = dist.find(key) == dist.end();
        cout << "\ncheck_key returns\n";
        cout << returntype;
        cout << "\n";
    }
    return !(dist.find(key) == dist.end());
}

bool isInside(int row, int col) {
    if ((row >= 0) && (row < xyMax) &&
        (col >= 0) && (col < xyMax)) {
        return true;
    } else {
        return false;
    }
}

int getRandomNumber(int min, int max) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range
    return distr(gen);
}

void setWorldToNullAt(int x, int y, world &w) {
    w.setFields('f', x, y);
}

void setPath(world &world, vector<vector<int>> &distanceMirror, Point dest, Point src) {
    Point curr = dest;
    Point temp;
    unsigned long rand;
    setWorldToNullAt(dest.x, dest.y, world);
    while (getPointHash(curr) != getPointHash(src)) {
        vector<Point> considerable = {};
        for (int i = 0; i < 4; i++) {
            int row = curr.x + rowNum[i];
            int col = curr.y + colNum[i];
            int currentDistance = distanceMirror.at(row).at(col);
            if (isInside(row, col) && currentDistance < distanceMirror.at(curr.x).at(curr.y) && currentDistance != 0) {
                temp = {row, col};
                considerable.push_back(temp);
            }
        }

        if (considerable.empty()) {
            return;
        } else {
            //decide where to go by random chance
            if (considerable.size() == 1) {
                rand = 0;
            } else {
                rand = getRandomNumber(0, considerable.size() - 1);
            }
            curr = considerable.at(rand);
            setWorldToNullAt(curr.x, curr.y, world);
        }
    }
    setWorldToNullAt(src.x, src.y, world);
}
int pathfinder(world &w, Point src, Point dest, int mode) //mode = 1 then using as map generator, else distance tool
{
    unordered_map<Node, int, HashingNodes> dist;
    queue<Node> q;
    Node current = {
            src,
            nullptr,
            0
    };
    dist[current] = 0;
    q.push(current);
    auto distanceMirror = vector<vector<int>>(30, vector<int>(30, 0));
    Node curr;
    do {
        curr = q.front();
        q.pop();

        if (getNodeHash(curr) == getPointHash(dest)) {
            if (mode == 1) {
                setPath(w, distanceMirror, dest, src);
                return 0;
            } else {
                return curr.distance + 1;
            }
        }

        for (int i = 0; i < 4; i++) {
            int row = curr.point.x + rowNum[i];
            int col = curr.point.y + colNum[i];

            Node check = {{row, col}, &curr, curr.distance + 1};

            if (isInside(row, col) && !(check_key(dist, check))) {
                dist[check] = curr.distance + 1;
                distanceMirror.at(row).at(col) = curr.distance + 1;
                q.push(check);
            }
        }
    } while (!q.empty());

    //throw std::invalid_argument( "Points to pathfind given not connectable. Aborting everything - should we change this?" ); //TODO: Is this dangerous?
    return -1;
}

void cancelExecution(string reason, string position) {
    if (debugMode != -1) {
        cout << "Execution will come to a hold at: " << position;
        cout << "Reason:\n\n";
        throw std::invalid_argument(reason);
    } else {
        cout
                << "Something went wrong. If you want to debug, try turning on debug mode. Execution will proceed due to production mode enabled. Beware:";
    }
}

void pathGenerator(int amount, world &w) {
    int validPath;
    for (int i = amount; i >= 0; i--) {
        Point to = {
                getRandomNumber(1, 28),
                getRandomNumber(1, 28)
        };
        Point from = {
                getRandomNumber(1, 28),
                getRandomNumber(1, 28)
        };
        validPath = pathfinder(w, from, to, 1);
        if (validPath != 0) {
            cancelExecution("Path was not valid, validPath returned !=0", "pathGenerator->pathfinder");
        }
    }
}

void savePathGenerator(int amount, world &w) {
    int validPath;
    Point to = {
            getRandomNumber(1, 28),
            getRandomNumber(1, 28)
    };
    for (int i = amount; i >= 0; i--) {
        Point from = {
                getRandomNumber(1, 28),
                getRandomNumber(1, 28)
        };
        validPath = pathfinder(w, from, to, 1);
        if (validPath != 0) {
            cancelExecution("Path was not valid, validPath returned !=0", "pathGenerator->pathfinder");
        }
    }
}

world &generateNewWorld(world &worldTemplate, int clearness) {
    pathGenerator(clearness, worldTemplate);
    if (debugMode != 0) {
        worldTemplate.printWorld();
    }
    return worldTemplate;
}

bool checkFree(world &w, Point checked) {
    if (w.getFields(checked.x, checked.y) == 'f') {
        return true;
    } else {
        return false;
    }
}

vector<int> giveMoveableSpots(world &w, Point p) {
    vector<int> movements = {};
    for (int i = 0; i < 4; i++) {
        int row = p.x + rowNum[i];
        int col = p.y + colNum[i];
        Point temp = {
                row,
                col
        };
        if (checkFree(w, temp)) {
            movements.at(i) = 0;
        } else {
            movements.at(i) = 1;
        }
    }
    return movements;
}

bool placeItem(world &w, Point whereToPlace, char what) {
    w.setFields(what, whereToPlace.x, whereToPlace.y);
    return true;
}

Point getRandomFreePlace(world &w) {

    for (int i = 0; i < 1000000; i++) {
        Point temp = {
                getRandomNumber(1, 28),
                getRandomNumber(1, 28)
        };
        if (checkFree(w, temp)) {
            return temp;
        }
    }
    if (debugMode != -1) {
        cancelExecution("Couldnt find random free place after 1M tries", "getRandomFreePlace->//");
        Point unsafe = {
                -9999,
                -9999
        };
        return unsafe;
    } else {
        cout << "WARNING: Couldnt find point after 1M tries";
        Point unsafe = {
                -9999,
                -9999
        };
        return unsafe;
    }
}

int getDistance(world &w, Point from, Point to) {
    int distance = pathfinder(w, from, to, 0);
    if (distance == -1) {
        if (debugMode != -1) {
            cancelExecution("No distance found", "checkDistance->pathfinder");
            return -9999;
        } else {
            cout << "WARNING: Could not find distance for two points at checkdistance";
            return -9999;
        }
    } else {
        return distance;
    }
}

bool isDistanceLessThan(world &w, int distance, Point from, Point to) {
    int temp = getDistance(w, from, to);
    if (temp < distance) {
        if (debugMode != 0) {
            cout << "\n\nisDistanceLessThan returns true\n\n";
        }
        return true;
    } else {
        if (debugMode != 0) {
            cout << "\n\nisDistanceLessThan returns false\n\n";
        }
        return false;
    }
}

void testWorldGeneration(world &w) {
    if (debugMode != 0) {
        auto free = getRandomFreePlace(w);
        cout << pointToString(free);
        cout << isDistanceLessThan(w, 100, {1, 1}, {9, 9});
    } else {
        cout << "Debug method called without wanting to debug. Set debugMode !=0";
    }
}

string pointToString(Point p) {
    auto xIs = std::to_string(p.x);
    auto yIs = std::to_string(p.y);
    return "X is: " + xIs + " | Y is: " + yIs;
}
