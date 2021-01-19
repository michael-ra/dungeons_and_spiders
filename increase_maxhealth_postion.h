//
// Created by Tim on 13.01.2021.
//

#ifndef DUNGEONCRAWLER_INCREASE_MAXHEALTH_POSTION_H
#define DUNGEONCRAWLER_INCREASE_MAXHEALTH_POSTION_H


//
// Created by Tim on 13.01.2021.
//

#include "item.h"

class Increase_MaxHealth_Potion : Item {

    int max_potion;

public:
    Increase_MaxHealth_Potion() {
        max_potion = 2;
        entity = 'p';
    }

    void increase_max_health();

};


#endif //DUNGEONCRAWLER_INCREASE_MAXHEALTH_POSTION_H
