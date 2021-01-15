#include <iostream>
#include "world.h"
#include <bits/stdc++.h>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
using namespace std;
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

bool check_key(unordered_map<Node, int, HashingNodes> dist, Node key)
{
    //bool returntype = dist.find(key) == dist.end(); //todo remove test
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
    auto distanceMirror = vector<vector<int>>(30, vector<int> (30, NULL));
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

            if(isInside(row,col) && !(check_key(dist,check))) {
                dist[check] = curr.distance+1;
                distanceMirror.at(row).at(col) = curr.distance+1;
                q.push(check);
            }
        }
    }while(!q.empty());

    //throw std::invalid_argument( "Points to pathfind given not connectable. Aborting everything - should we change this?" ); //TODO: Is this dangerous?
    return -1;
}

void cancelExecution(string reason, string position) {
    cout << "Execution will come to a hold at: " << position;
    cout << "Reason:\n\n";
    throw std::invalid_argument( reason );
}

//todo: ensure path valid while keeping two randoms that change ->everything connected?
int pathGenerator(int amount, world &w) {
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
int savePathGenerator(int amount, world &w) {
    int validPath;
    Point to = {
            getRandomNumber(1, 28),
            getRandomNumber(1, 28)
    };
    for(int i=amount; i>=0; i--) {
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



// Driver program to test above function
int main()
{

    world w;

    //
    //int x;
    //char aChar = '0' + x;
    //int x = aChar - '0';
    //


    pathGenerator(28,w);
    w.printWorld();


    return 0;
}