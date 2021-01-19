//
// Created by Tim on 17.01.2021.
//

#ifndef DUNGEONCRAWLER_WORLDUTIL_H
#define DUNGEONCRAWLER_WORLDUTIL_H


#include "worldutil.h"
#include <iostream>
#include "world.h"
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

struct Point {
    int x;
    int y;
};

struct Node {
    Point point;
    struct Node *previousNode;
    int distance;

    bool operator==(const Node &other) const {
        return
                (point.y == other.point.y && point.x == other.point.x);
    }
};

string pointToString(Point p);

struct HashingNodes {
    std::size_t operator()(const Node &n) const {
        using std::size_t;
        using std::hash;
        using std::string;

        return (hash<int>()((n.point.x + n.point.y * 30)));
    }
};


int testHashingNode(Node &n);

int getNodeHash(Node n);

int getPointHash(Point p);

bool check_key(unordered_map<Node, int, HashingNodes> dist, Node key);

//checks with environment variable so world isnt needed in pathfinder
bool isInside(int row, int col);


int getRandomNumber(int min, int max);

void setWorldToNullAt(int x, int y, world &w);

void setPath(world &world, vector<vector<int>> &distanceMirror, Point dest, Point src);

int pathfinder(world &w, Point src, Point dest, int mode);

void cancelExecution(string reason, string position);

//todo: ensure path valid while keeping two randoms that change ->everything connected?
void pathGenerator(int amount, world &w);

/*
 * Used to generate paths that have a connection to each other
 */
void savePathGenerator(int amount, world &w);

/*
 * Returns new world (type world), clearness = tunnels randomly generated (the higher the more tunnels randomly cleared)
 */
world &generateNewWorld(world &worldTemplate, int clearness);

/*
 * Returns weather the field on the inputted world is free
 */
bool checkFree(world &w, Point checked);

/*
 * Give free movement directions
 * vecotr until now: L-O-R-U
 * 0 - moveable, 1 - obstructed, ...
 * TODO: (IMPORTANT FOR FEATURES) ---- Add diagonal movement
 */
[[maybe_unused]] vector<int> giveMoveableSpots(world &w, Point p);

/*
 * Returns true after placed item
 */
[[maybe_unused]] bool placeItem(world &w, Point whereToPlace, char what);

/*
 * Returns random free place on the world
 * Possibly unsafe if all is full
 */
Point getRandomFreePlace(world &w);

/*
 * Checks two points for distance and outputs it
 */
int getDistance(world &w, Point from, Point to);

bool isDistanceLessThan(world &w, int distance, Point from, Point to);

/*
 * Test method for world generation (only if debug != 0)
 */
void testWorldGeneration(world &w);

#endif DUNGEONCRAWLER_WORLDUTIL_H


//DUNGEONCRAWLER_WORLDUTIL_H
