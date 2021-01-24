//
// Created by PC-VtB on 15.01.2021.
//

#ifndef test
#define test

#include <iostream>
#include "object/world.h"
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
/*
 * TODO move to another utils file
 * -1 = resumeWithErrors
 * 0 = production
 * 1 = debug/development
 */
int debugMode = 1;
/*
 * Convention variable: playing field is 30x30
 */

/*
 * TODO util for printing with newline automatic formatting and ordering (prio very low)
 */
int xyMax = 30;
int const rowNum[] = {-1, 0, 0, 1};
int const colNum[] = {0, -1, 1, 0};

struct Point
{
    int x;
    int y;
};

struct Node
{
    Point point;
    struct Node *previousNode;
    int distance;

    bool operator==(const Node &other) const { return
                (point.y == other.point.y && point.x == other.point.x);
    }
};

string pointToString(Point p) {
    auto xIs = std::to_string(p.x);
    auto yIs = std::to_string(p.y);
    return "X is: " + xIs + " | Y is: " + yIs;
}

struct HashingNodes {
    std::size_t operator()(const Node &n) const
    {
        using std::size_t;
        using std::hash;
        using std::string;

        return (hash<int>()((n.point.x + n.point.y * 30) ));
    }
};


int testHashingNode(Node& n) {
    return (hash<int>()((n.point.x + n.point.y * 30) ));
}

int getNodeHash(Node n) {
    return n.point.x + n.point.y * 30;
}

int getPointHash(Point p) {
    return p.x + p.y * 30;
}

bool checkKey(unordered_map<Node, int, HashingNodes> dist, Node key) {
    if (debugMode != 0) {
        bool returntype = dist.find(key) == dist.end();
        cout << "\ncheckkey returns\n";
        cout << returntype;
        cout << "\n";
    }
    return !(dist.find(key) == dist.end());
}

//checks with environment variable so world isnt needed in pathfinder
bool isInside(int row, int col)
{
    if( (row >= 0) && (row < xyMax) &&
        (col >= 0) && (col < xyMax) ) {
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
    w.setFields('f',x,y);
}

void setPath(world &world, vector<vector<int>> &distanceMirror, Point dest, Point src) {
    Point curr = dest;
    Point temp;
    unsigned long rand;
    setWorldToNullAt(dest.x, dest.y, world);
    while(getPointHash(curr) != getPointHash(src)) {
        vector<Point> considerable = {};
        for(int i=0; i<4; i++) {
            int row = curr.x + rowNum[i];
            int col = curr.y + colNum[i];
            int currentDistance = distanceMirror.at(row).at(col);
            if(isInside(row,col) && currentDistance < distanceMirror.at(curr.x).at(curr.y) && currentDistance != 0) {
                temp = {row,col};
                considerable.push_back( temp);
            }
        }

        if(considerable.empty()) {
            return;
        } else {
            //decide where to go by random chance
            if(considerable.size() == 1) {
                rand = 0;
            } else {
                rand = getRandomNumber(0, considerable.size()-1);
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
    auto distanceMirror = vector<vector<int>>(30, vector<int> (30, 0));
    Node curr;
    do{
        curr = q.front();
        q.pop();

        if(getNodeHash(curr) == getPointHash(dest)) {
            if(mode == 1) {
                setPath(w, distanceMirror, dest, src);
                return 0;
            } else {
                return curr.distance+1;
            }
        }

        for(int i=0; i<4; i++) {
            int row = curr.point.x + rowNum[i];
            int col = curr.point.y + colNum[i];

            Node check = { {row,col}, &curr, curr.distance+1 };

            if(isInside(row,col) && !(checkKey(dist,check))) {
                dist[check] = curr.distance+1;
                distanceMirror.at(row).at(col) = curr.distance+1;
                q.push(check);
            }
        }
    }while(!q.empty());

    //throw std::invalid_argument( "Points to pathfind given not connectable. Aborting everything - should we change this?" ); //TODO: Is this dangerous?
    return -1;
}


//gives you Point on path for given player and enemy so that you can walk shortest distance, int is distance for when you want to get a valid point
Point pathGiver(world &w, Point player, Point enemy, int distanceCheck)
{
    unordered_map<Node, int, HashingNodes> dist;
    queue<Node> q;
    Node current = {
            player,
            nullptr,
            0
    };
    dist[current] = 0;
    q.push(current);
    auto distanceMirror = vector<vector<int>>(30, vector<int> (30, 0));
    Node curr;
    do{
        curr = q.front();
        q.pop();

        if(getNodeHash(curr) == getPointHash(enemy)) {
            int distancePrev = 999;
            Point goTo = {
                    -999,-999
            };
            for(int i=0; i<4; i++) {
                int row = enemy.x + rowNum[i];
                int col = enemy.y + colNum[i];

                if(distanceMirror.at(row).at(col) != 0 && distanceMirror.at(row).at(col) < distancePrev) {
                    distancePrev = distanceMirror.at(row).at(col);
                    goTo = {
                            row,col
                    };
                }

                if(distancePrev <= distanceCheck) {
                    return goTo;
                } else {
                    return {
                        -999,-999
                    };
                }
            }
        }

        for(int i=0; i<4; i++) {
            int row = curr.point.x + rowNum[i];
            int col = curr.point.y + colNum[i];

            Node check = { {row,col}, &curr, curr.distance+1 };

            if(isInside(row,col) && !(checkKey(dist,check)) && w.getFields(row,col) != '#') {
                dist[check] = curr.distance+1;
                distanceMirror.at(row).at(col) = curr.distance+1;
                q.push(check);
            }
        }
    }while(!q.empty());

    return {
            -999,-999
    };
}


void cancelExecution(string reason, string position) {
    if(debugMode != -1) {
        cout << "Execution will come to a hold at: " << position;
        cout << "\nReason:\n\n";
        throw std::invalid_argument(reason);
    } else {
        cout << "\nSomething went wrong. If you want to debug, try turning on debug mode. Execution will proceed due to production mode enabled. Beware:";
    }
}

//todo: ensure path valid while keeping two randoms that change ->everything connected?
void pathGenerator(int amount, world &w) {
    int validPath;
    for(int i=amount; i>=0; i--) {
        Point to = {
                getRandomNumber(1, 28),
                getRandomNumber(1, 28)
        };
        Point from = {
                getRandomNumber(1, 28),
                getRandomNumber(1, 28)
        };
        validPath = pathfinder(w,from,to,1);
        if(validPath != 0) {
            cancelExecution("Path was not valid, validPath returned !=0","pathGenerator->pathfinder");
        }
    }
}

/*
 * Used to generate paths that have a connection to each other
 */
void savePathGenerator(int amount, world &w) {
    int validPath;
    Point from = {
            1,
            1
    };
    Point to_for = {-999, -999};
    Point to = {
            getRandomNumber(1, 28),
            getRandomNumber(1, 28)
    };
    validPath = pathfinder(w, from, to, 1);
    if (validPath != 0) {
        cancelExecution("Path was not valid, validPath returned !=0", "pathGenerator->pathfinder");
    }

    for (int i = amount; i >= 0; i--) {
        to_for = {
                getRandomNumber(1, 28),
                getRandomNumber(1, 28)
        };

        validPath = pathfinder(w, to, to_for, 1);
        if (validPath != 0) {
            cancelExecution("Path was not valid, validPath returned !=0", "pathGenerator->pathfinder");
        }
        to = to_for;


        Point end = {28, 28};
        validPath = pathfinder(w, to, end, 1);
        if (validPath != 0) {
            cancelExecution("Path was not valid, validPath returned !=0", "pathGenerator->pathfinder");
        }

    }
}

/*
 * Returns new world (type world), clearness = tunnels randomly generated (the higher the more tunnels randomly cleared)
 */
world& generateNewWorld(world &worldTemplate, int clearness) {
    savePathGenerator(clearness, worldTemplate);
    if(debugMode != 0) {
        worldTemplate.printWorld();
    }
    return worldTemplate;
}

/*
 * Returns weather the field on the inputted world is free
 */
bool checkFree(world &w, Point checked) {
    if(w.getFields(checked.x,checked.y) == 'f') {
        return true;
    } else {
        return false;
    }
}

/*
 * Give free movement directions
 * vecotr until now: L-O-R-U
 * 0 - moveable, 1 - obstructed, ...
 * TODO: (IMPORTANT FOR FEATURES) ---- Add diagonal movement
 */
[[maybe_unused]] vector<int> giveMoveableSpots(world &w, Point p) {
    vector<int> movements = {1,1,1,1};
    for(int i=0; i<4; i++) {
        int row = p.x + rowNum[i];
        int col = p.y + colNum[i];
        Point temp = {
                row,
                col
        };
        if(checkFree(w,temp)) {
            movements.at(i) = 0;
        } else {
            movements.at(i) = 1;
        }
    }
    return movements;
}

/*
 * Returns true after placed item
 */
[[maybe_unused]] bool placeItem(world &w, Point whereToPlace, char what) {
    w.setFields(what, whereToPlace.x, whereToPlace.y);
    return true;
}

/*
 * Returns random free place on the world
 * Possibly unsafe if all is full
 */
Point getRandomFreePlace(world &w) {

    for(int i=0; i<1000000; i++) {
        Point temp = {
                getRandomNumber(1, 28),
                getRandomNumber(1, 28)
        };
        if (checkFree(w, temp)) {
            return temp;
        }
    }
    if(debugMode != -1) {
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

/*
 * Checks two points for distance and outputs it
 */
int getDistance(world &w, Point from, Point to) {
    int distance = pathfinder(w,from,to,0);
    if(distance == -1) {
        if(debugMode != -1) {
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
//TODO: check if returns 2 when nearby - while not checked just use 2 ffs

bool isDistanceLessThan(world &w, int distance, Point from, Point to) {
    int temp = getDistance(w,from,to);
    if(temp < distance) {
        if(debugMode != 0) {
            cout << "\n\nisDistanceLessThan returns true\n\n";
        }
        return true;
    } else {
        if(debugMode != 0) {
            cout << "\n\nisDistanceLessThan returns false\n\n";
        }
        return false;
    }
}

/*
 * Test method for world generation (only if debug != 0)
 * this is a-test
 */
void testWorldGeneration(world &w) {
    if(debugMode != 0) {
        auto free = getRandomFreePlace(w);
        cout << pointToString(free);
        cout << isDistanceLessThan(w, 100, {1, 1}, {9, 9});
    } else {
        cout << "Debug method called without wanting to debug. Set debugMode !=0";
    }
}
#endif
