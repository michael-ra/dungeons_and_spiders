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
        health = 5;
        dps = 5;
    }

    //Gehe davon aus, dass halt die steurung also keyabfrage und dann wenn key == keydown dann down etc
    void down_movement() {
        y += 1;
    }

    void up_movement() {
        y -= 1;
    }

    void left_movement() {
        x -= 1;
    }

    void right_movement() {
        x += 1;
    }


};