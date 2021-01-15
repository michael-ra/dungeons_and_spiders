//
// Created by PC-VtB on 12.01.2021.
//

#include "test.hpp"
#include <iostream>
using namespace std;



std::vector<test::GameObject *> test::getGameObjectsOnMap() const {
    return gameObjectsOnMap;
}

void test::setGameObjectsOnMap(const std::vector<GameObject *> &objectsOnMap) {
    test::gameObjectsOnMap = objectsOnMap;
}

test::test() {

}

void hello() {
    cout << "ihdjihd";
}

char test::getFields(int x, int y) {
    return fields[x][y];
}

void test::setFields(char insert, int x, int y) {
    test::fields[x][y] = insert;
}