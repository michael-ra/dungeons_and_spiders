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
    Node * previousNode;

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

void setPaths(Node node, world &World) {

}


int pathfinder(world &w, Point src, Point dest)
{
    int distance = 0;
    bool end = false;
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
    Node temp{};

    do{
        Node curr = q.front();

        if(getNodeHash(curr) == getPointHash(dest)) {
            w.setFields('#', temp.point.x, temp.point.y);
            Node which = *temp.previousNode;
            int i = 0;
            while (which.hasNext()) {
                w.setFields('#', which.point.x, which.point.y);
                which = *which.previousNode;
                i++;
            }
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
            Node check = { {row,col}, &curr };
            bool isI = isInside(row,col);
            bool chxkK = !(check_key(dist,check));
            if(isInside(row,col) && !(check_key(dist,check))) {
                temp = { {row,col}, &curr };
                dist[temp] = dist[curr]+1;
                q.push(temp);
                }
            }
    }while(!q.empty());

    throw std::invalid_argument( "Points to pathfind given not connectable. Aborting everything - should we change this?" ); //TODO: Is this dangerous?

}


// Driver program to test above function
int main()
{
    world w;
    //cout << w.getFields(1,1);

    Point source = {1, 1};
    Point dest = {9, 7};

    auto i = pathfinder(w,source,dest);

    for(int i=0; i<30; i++) {
        for(int p=0; p<30; p++) {
            if(w.getFields(i, p) == '#') {
                cout << w.getFields(i, p) << "an Stelle" << i << "-" << p;
            }
        }
        cout << "\n\n";
    }

    return 0;
}