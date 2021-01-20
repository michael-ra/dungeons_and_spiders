//
// Created by Tim on 12.01.2021.
//

#ifndef DUNGEONCRAWLER_PLAYER_H
#define DUNGEONCRAWLER_PLAYER_H


//
// Created by Tim on 12.01.2021.
//



#include "game_object.h"

class Player : public Game_Object {

public:
    int health;
    int dps;

    Player() {
        entity = '#';
        health = 5;
        dps = 5;
    }

    //Gehe davon aus, dass halt die steurung also keyabfrage und dann wenn key == keydown dann down etc
    bool down_movement(world &w);

    bool up_movement(world &w);

    bool left_movement(world &w);

    bool right_movement(world &w);

    //Setter
    void set_health(int health);

    void set_dps(int dps);

    //Getter

    int get_health();

    int get_dps();

    //If a collision appears take damage and go back to last_position
    void damage(int dps_of_enemy);

    //true: wenn leben unter 0
    bool dead();

    //Wenn Spieler mit einer Healthpostion kollidiert, dann erhoehe das leben des spielers (limitiert durch max_health des Spielers
    void increase_health(int potion);
};


#endif //DUNGEONCRAWLER_PLAYER_H
