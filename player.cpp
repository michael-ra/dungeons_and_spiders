//
// Created by Tim on 12.01.2021.
//

#include "player.h"
#include "game_object.cpp"

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
    bool down_movement(world &w) {
        Point p = point;
        last_position = point;
        p.y += 1;
        if (checkFree(w, p)) {
            point.y += 1;
        } else if (w.is_object(w, p.x, p.y)) {
            return true;
        }
    }

    bool up_movement(world &w) {
        Point p = point;
        last_position = point;
        p.y -= 1;
        if (checkFree(w, p) || w.is_object(w, p.x, p.y)) {
            point.y -= 1;
        } else if (w.is_object(w, p.x, p.y)) {
            return true;
        }
    }

    bool left_movement(world &w) {
        Point p = point;
        last_position = point;
        p.x -= 1;
        if (checkFree(w, p)) {
            point.x -= 1;
        } else if (w.is_object(w, p.x, p.y)) {
            return true;
        }
    }

    bool right_movement(world &w) {
        Point p = point;
        last_position = point;
        p.x += 1;
        if (checkFree(w, p)) {
            point.x += 1;
        } else if (w.is_object(w, p.x, p.y)) {
            return true;
        }
    }

    //Setter
    void set_health(int health) {
        if (health >= 0) {
            this->health = health;
        }
    }

    void set_dps(int dps) {
        if (dps >= 0) {
            this->dps = dps;
        }
    }

    //Getter

    int get_health() {
        return health;
    }

    int get_dps() {
        return dps;
    }

    //If a collision appears take damage and go back to last_position
    void damage(int dps_of_enemy) {
        health -= dps_of_enemy;
        point = last_position;
    }

    //true: wenn leben unter 0
    bool dead() {
        if (health <= 0) {
            return true;
        }
        return false;
    }
};