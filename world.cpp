//
// Created by PC-VtB on 12.01.2021.
//

#include "world.h"



std::vector<world::GameObject *> world::getGameObjectsOnMap() const {
    return gameObjectsOnMap;
}

void world::setGameObjectsOnMap(const std::vector<GameObject *> &objectsOnMap) {
    world::gameObjectsOnMap = objectsOnMap;
}

void setWorldAt(int p, int q, char c) {
    world::fields[p][q] = c;
}

world::world() {
    for (int p = 0; p < 30; p++) {
        for(int q = 0; q < 30; q++) {
            fields[p][q] = '#';
        }
    }
};
