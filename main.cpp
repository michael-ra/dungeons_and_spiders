#include <iostream>
#include "world.h"
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int xyMax = 30;

struct Point
{
    int x;
    int y;
};

struct Node
{
    Point point;
    Node *previousNode;

    bool operator==(const Node &other) const { return
        (point.y == other.point.y && point.x == other.point.x && previousNode == other.previousNode);
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
    bool returntype = dist.find(key) == dist.end();
    return !(dist.find(key) == dist.end());
}

bool isInside(int row, int col)
{
    if( (row >= 0) && (row < xyMax) &&
           (col >= 0) && (col < xyMax) ) {
        return true;
    } else {
        return false;
    }
}


int BFS(int mat[30][30], Point src, Point dest)
{
    int distance = 0;
    unordered_map<Node, int, HashingNodes> dist;
    queue<Node> q;
    Node current = {
            src,
            NULL
    };
    dist[current] = 0;
    q.push(current);
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};
    Node destination;

    do{
        Node curr = q.front();

        if(getNodeHash(curr) == getPointHash(dest)) {
            destination = curr; //get to destination
            break;
        }

        q.pop();

        int same; //testing int
        same = testHashingNode(curr);

        for(int i=0; i<4; i++) {
            int row = curr.point.x + rowNum[i];
            int col = curr.point.y + colNum[i];

            if(same != testHashingNode(curr)) {return -2;} //check for consistency, else fail -> to be implemented as todo: unit test
            /* cout << "\nCurrent node sollte gleich sein\n";
            cout << testHashingNode(curr);
            cout << "\nSollte unterschiedlich sein\n";
            cout << testHashingNode(temp);
            cout << "\n....         ......\n\n";
            bool shouldBeTure = check_key(dist,curr);
            bool shouldBeFalse = check_key(dist,temp);
            cout << testHashingNode(temp);
             */

            Node temp = { {row,col}, &curr };

            if(isInside(row,col) && !(check_key(dist,temp))) {
                dist[temp] = dist[curr]+1;
                q.push(temp);
            }
        }

    }while(!q.empty());

    cout << dist[destination];
    return -1;

}

// Driver program to test above function
int main()
{
    int world[30][30] = {};

    Point source = {0, 0};
    Point dest = {3, 4};

    int dist = BFS(world, source, dest);

    if (dist != -1)
        cout << "Shortest Path is " << dist ;
    else
        cout << "Shortest Path doesn't exist";

    return 0;
}