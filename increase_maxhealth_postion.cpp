//
// Created by Tim on 13.01.2021.
//

#include "increase_maxhealth_postion.h"
#include "item.cpp"

class Increase_MaxHealth_Potion : Item {

    int max_potion;

    Increase_MaxHealth_Potion() {

        max_potion = 2;

    }

    void increase_max_health() {
        max_health += max_potion;

    }

};