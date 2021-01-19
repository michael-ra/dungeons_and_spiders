//
// Created by Tim on 12.01.2021.
//

#ifndef DUNGEONCRAWLER_ENEMY_GOBLIN_H
#define DUNGEONCRAWLER_ENEMY_GOBLIN_H


//
// Created by Tim on 12.01.2021.
//



#include "enemy.h"
#include <vector>

using namespace std;


class Goblin : public Enemy {

public:

    Goblin() {
        health = 10;
        dps = 2;
        entity = 'g';
    }

    //O R U L
    void movement(world &w);
};


#endif //DUNGEONCRAWLER_ENEMY_GOBLIN_H
