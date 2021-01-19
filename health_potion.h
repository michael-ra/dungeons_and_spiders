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
    void increase_health(int players_health);
};


#endif //DUNGEONCRAWLER_HEALTH_POTION_H
