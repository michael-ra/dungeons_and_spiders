//
// Created by Tim on 12.01.2021.
//

#include "enemy.h"
#include "game_object.cpp"

class Enemy : public Game_Object {
protected:


    Enemy() {

    }
    //Setter

    void set_health(int health) {
        //Setter for health
        this->health = health;
    }

    void set_dps(int dps) {
        //Setter for damage
        this->dps = dps;
    }

    //Getter

    int get_health() {
        //Get the amount of health left
        return health;
    }

    int get_dps() {
        //Get the damage points of the enemy
        return dps;
    }

    void take_damage(int damage) {
        //reduce damage when hit
        this->health -= damage;
    }

    bool is_dead() {
        if (health <= 0) {
            return true;
        } else {
            return false;
        }
    }

    //If it moves on top of Player: do damage and then step back to old position
    void do_damage(int dmg_of_player) {
        health -= dmg_of_player;
        point = last_position;
    }


};