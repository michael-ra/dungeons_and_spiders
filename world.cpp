//
// Created by PC-VtB on 12.01.2021.
//

#include "world.h"
#include <iostream>
using namespace std;



std::vector<world::GameObject *> world::getGameObjectsOnMap() const {
    return gameObjectsOnMap;
}

void world::setGameObjectsOnMap(const std::vector<GameObject *> &objectsOnMap) {
    world::gameObjectsOnMap = objectsOnMap;
}

world::world() {
    vec = vector<vector<char>>(30, vector<char> (30, '#'));
}

char world::getFields(int x, int y) {
    return vec.at(x).at(y);
}

void world::setFields(char insert, int x, int y) {
    world::vec.at(x).at(y) = insert;
}

void world::printWorld() {
    for(int i=0; i<30; i++) {
        for(int p=0; p<30; p++) {
            cout << getFields(i, p);
        }
        cout << "\n";
    }
}