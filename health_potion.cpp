//
// Created by Tim on 13.01.2021.
//

#include "health_potion.h"
#include "item.cpp"

class HealthPotion : public Item {

    //grosse und kleine healthpotion; Gross: 'O' klein: 'o'

public:

    HealthPotion(char size) {
        if (size == 'O') {
            potion = 5;
            entity = size;
        } else if (size == 'o') {
            potion = 3;
            entity = size;
        }

    }

    //Wenn Spieler mit einer Healthpostion kollidiert, dann erhoehe das leben des spielers (limitiert durch max_health des Spielers
    void increase_health(int players_health) {

        if ((players_health += potion) >= max_health) {
            players_health = max_health;
        } else {
            players_health += potion;
        }
    }


};
