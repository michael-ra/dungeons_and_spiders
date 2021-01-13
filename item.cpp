//
// Created by Tim on 13.01.2021.
//

#include "item.h"
#include "game_object.cpp"

class Item : public Game_Object {

    //Armor einfach mehr leben oder extra speciales
    //und macht das so sinn weil dann ja enemy und item recht identisch sind und ob man item nicht unterklasse von enemy macht
protected:

    int potion;

    Item() {

    }

    //Setter

    void set_additional_health(int health) {
        //Setter for health
        this->health = health;
    }

    void set_additional_dps(int dps) {
        //Setter for damage
        this->dps = dps;
    }

    //Getter

    int get_additional_health() {
        //Get the amount of health left
        return health;
    }

    int get_additional_dps() {
        //Get the damage points of the enemy
        return dps;
    }

};