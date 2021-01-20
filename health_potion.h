//
// Created by Tim on 13.01.2021.
//

#ifndef DUNGEONCRAWLER_HEALTH_POTION_H
#define DUNGEONCRAWLER_HEALTH_POTION_H

//
// Created by Tim on 13.01.2021.
//

#include "item.h"

class HealthPotion : public Item {

    //grosse und kleine healthpotion; Gross: 'O' klein: 'o'

    int potion;

public:


    HealthPotion() {
        this->potion = 3;
    }


    HealthPotion(char size) {
        if (size == 'O') {
            potion = 5;
            entity = size;
        } else if (size == 'o') {
            potion = 3;
            entity = size;
        }

    }

    //getter

    int get_potion_size() {
        return potion;
    }

    //setter
    void set_potion_size(int potion) {
        if (potion > 0) {
            this->potion = potion;
        }
    }


};


#endif //DUNGEONCRAWLER_HEALTH_POTION_H
