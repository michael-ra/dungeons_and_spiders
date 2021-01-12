//
// Created by PC-VtB on 12.01.2021.
//

#ifndef NEWLY_WORLD_H
#define NEWLY_WORLD_H

#include <vector>
#include <array>

extern char fields[30][30];

class world {

private:
    //TODO IMPORTANT: use GameObject Type of Tim
    class GameObject {};

public:
    world();
private:

    std::vector<GameObject*> gameObjectsOnMap;
public:

    [[nodiscard]] std::vector<GameObject *> getGameObjectsOnMap() const;

    void setGameObjectsOnMap(const std::vector<GameObject *> &objectsOnMap);

    static void setWorldAt(int p, int q, char c);

    static char getWorldAt(int p, int q);
};

#endif //NEWLY_WORLD_H
