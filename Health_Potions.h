//
// Created by Tim on 20.01.2021.
//

#ifndef DUNGEONCRAWLER_HEALTH_POTIONS_H
#define DUNGEONCRAWLER_HEALTH_POTIONS_H

#include "health_potion.h"


class Health_Potions {

public:
    HealthPotion *scearch_health_potion(vector<HealthPotion *> health_potions, int x, int y) {
        for (int i = 0; i < health_potions.size(); i++) {

            if (health_potions.at(i)->get_x_point() == x &&
                health_potions.at(i)->get_y_point() == y) {
                return health_potions.at(i);
            }
        }
    }
};


#endif //DUNGEONCRAWLER_HEALTH_POTIONS_H
