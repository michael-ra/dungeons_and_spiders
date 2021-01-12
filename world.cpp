//
// Created by PC-VtB on 12.01.2021.
//

#include "world.h"

char fields[30][30];

std::vector<world::GameObject *> world::getGameObjectsOnMap() const {
    return gameObjectsOnMap;
}

void world::setGameObjectsOnMap(const std::vector<GameObject *> &objectsOnMap) {
    world::gameObjectsOnMap = objectsOnMap;
}

world::world() {
};
