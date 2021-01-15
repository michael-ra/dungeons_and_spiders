//
// Created by Tim on 13.01.2021.
//

#include "increase_dps_potion.h"
#include "item.cpp"

class IncreaseDpsPotion : Item {

    //Zwei Staerke Traenge; Small: 'i' Big: 'I'

protected:

    int extra_dps;

public:
    IncreaseDpsPotion(char type) {
        if (type == 'i') {
            extra_dps = 1;
        } else {
            extra_dps = 3;
        }
    }

    void increase_dmg() {

        dps += extra_dps;

    }

};