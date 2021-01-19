//
// Created by Tim on 12.01.2021.
//

#ifndef DUNGEONCRAWLER_ENEMY_H
#define DUNGEONCRAWLER_ENEMY_H


//
// Created by Tim on 12.01.2021.
//


#include "game_object.h"

class Enemy : public Game_Object {
protected:


    Enemy() {

    }

    //Setter
    void set_health(int health);

    void set_dps(int dps);

    //Getter
    int get_health();

    int get_dps();

    void take_damage(int damage);

    bool is_dead();

    //If it moves on top of Player: do damage and then step back to old position
    void do_damage(int dmg_of_player);
};

#endif //DUNGEONCRAWLER_ENEMY_H
