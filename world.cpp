//
// Created by Tim on 17.01.2021.
//

#include "world.h"
//
// Created by PC-VtB on 12.01.2021.
//

#include <algorithm>
#include "world.h"
#include <iostream>

using namespace std;


vector<world::GameObject *> world::getGameObjectsOnMap() const {
    return gameObjectsOnMap;
}

void world::setGameObjectsOnMap(const std::vector<GameObject *> &objectsOnMap) {
    world::gameObjectsOnMap = objectsOnMap;
}

world::world() {
    vec = vector<vector<char>>(30, vector<char>(30, '#'));
}

char world::getFields(int x, int y) {
    return vec.at(x).at(y);
}

void world::setFields(char insert, int x, int y) {
    world::vec.at(x).at(y) = insert;
}

void world::printWorld() {
    for (int i = 0; i < 30; i++) {
        for (int p = 0; p < 30; p++) {
            cout << getFields(i, p);
        }
        cout << "\n";
    }
}

//added by Tim
bool world::is_object(world &w, int x, int y) {

    if (w.getFields(x, y) == 'i' || w.getFields(x, y) == 'I' ||
        w.getFields(x, y) == 'o' || w.getFields(x, y) == 'O' || w.getFields(x, y) == 'g' ||
        w.getFields(x, y) == 'k' || w.getFields(x, y) == 'p' || w.getFields(x, y) == '#') {
        return true;
    }
    return false;

}

/*
 * TODO: if world contains char method
 */