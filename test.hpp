//
// Created by PC-VtB on 12.01.2021.
//

#ifndef NEWLY_TEST_HPP
#define NEWLY_TEST_HPP


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

class test {

private:
    //TODO IMPORTANT: use GameObject Type of Tim
    class GameObject {};

public:
    test();
    void debugWorld();
    void hello();
private:
    std::unique_ptr<std::unique_ptr<char[]>[]> fields;

private:
    std::vector<GameObject*> gameObjectsOnMap;
public:
    const unique_ptr<std::unique_ptr<char[]>[]> &getFields() const;

    void setFields(const unique_ptr<std::unique_ptr<char[]>[]> &fields);

public:

    [[nodiscard]] std::vector<GameObject *> getGameObjectsOnMap() const;

    void setGameObjectsOnMap(const std::vector<GameObject *> &objectsOnMap);

    void setFields(char insert, int x, int y);

    void debugWorld(test *w);

    char getFields(int x, int y);
};

#endif //NEWLY_WORLD_H



#endif //NEWLY_TEST_HPP
