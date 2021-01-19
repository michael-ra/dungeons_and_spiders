//
// Created by Tim on 13.01.2021.
//

#ifndef DUNGEONCRAWLER_INCREASE_DPS_POTION_H
#define DUNGEONCRAWLER_INCREASE_DPS_POTION_H


//
// Created by Tim on 13.01.2021.
//


#include "item.h"

class IncreaseDpsPotion : Item {

    //Zwei Staerke Traenge; Small: 'i' Big: 'I'

protected:

    int extra_dps;

public:
    IncreaseDpsPotion(char type) {
        if (type == 'i') {
            extra_dps = 1;
            entity = type;
        } else if (type == 'I') {
            extra_dps = 3;
            entity = type;
        }

    }

    void increase_dmg();
};


#endif //DUNGEONCRAWLER_INCREASE_DPS_POTION_H
