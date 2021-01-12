//
// Created by PC-VtB on 12.01.2021.
//

#ifndef NEWLY_WORLD_H
#define NEWLY_WORLD_H

#include <vector>
#include <array>

class world {

private:
    //TODO IMPORTANT: use GameObject Type of Tim
    class GameObject {};

public:
    world();

    static char fields[30][30];
private:

    std::vector<GameObject*> gameObjectsOnMap;
public:

    [[nodiscard]] std::vector<GameObject *> getGameObjectsOnMap() const;

    void setGameObjectsOnMap(const std::vector<GameObject *> &objectsOnMap);
};

#endif //NEWLY_WORLD_H
