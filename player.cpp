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


};