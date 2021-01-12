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

    [[nodiscard]] bool hasNext() const {
        return previousNode != nullptr;
    }

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


int pathfinder(world world, Point src, Point dest)
{
    int distance = 0;
    unordered_map<Node, int, HashingNodes> dist;
    queue<Node> q;
    Node current = {
            src,
            nullptr
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



            return -1; //sucess
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

    throw std::invalid_argument( "Points to pathfind given not connectable. Aborting everything - should we change this?" ); //TODO: Is this dangerous?

}

int* setPaths(Node destination) {
    fields[destination.point.x][destination.point.y] = '\0';
    Node* which = destination.previousNode;
    while(which->hasNext()) {
        fields[which->point.x][which->point.y] = '\0';
        which = which->previousNode;
    }
}



// Driver program to test above function
int main()
{

    world world;
    for (int p = 0; p < 30; p++) {
        for(int q = 0; q < 30; q++) {
            fields[p][q] = '0';
        }
    }

    for (int p = 0; p < 30; p++) {
        for(int q = 0; q < 30; q++) {
            cout << fields[p][q] << " ";
        }
        cout << "\n\n";
    }

    Point source = {0, 0};
    Point dest = {3, 4};

    return 0;
}