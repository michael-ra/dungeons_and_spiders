//
// Created by Tim on 19.01.2021.
//

#ifndef DUNGEONCRAWLER_GOBLINS_H
#define DUNGEONCRAWLER_GOBLINS_H

#include "enemy_goblin.h"


class Goblins {
public:

    Goblin *scearch_goblins(vector<Goblin *> goblins, int x, int y) {
        for (int i = 0; i < goblins.size(); i++) {

            if (goblins.at(i)->get_x_point() == x &&
                goblins.at(i)->get_y_point() == y) {
                return goblins.at(i);
            }
        }
    }
};


#endif //DUNGEONCRAWLER_GOBLINS_H
