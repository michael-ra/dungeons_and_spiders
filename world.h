//
// Created by PC-VtB on 12.01.2021.
//

#ifndef NEWLY_WORLD_H
#define NEWLY_WORLD_H

#include <vector>
#include <array>
#include <bits/unique_ptr.h>
using namespace std;


//just extern because getter and setter for arrays are annoying to deal with
class world {

private:
    //TODO IMPORTANT: use GameObject Type of Tim
    class GameObject {};

public:
    world();
private:
    vector<vector<char>> vec;
     std::unique_ptr<std::unique_ptr<char[]>[]> fields;

private:
    std::vector<GameObject*> gameObjectsOnMap;

public:

    [[nodiscard]] std::vector<GameObject *> getGameObjectsOnMap() const;

    void setGameObjectsOnMap(const std::vector<GameObject *> &objectsOnMap);

    void setFields(char insert, int x, int y);

    char getFields(int x, int y);
};

#endif //NEWLY_WORLD_H
