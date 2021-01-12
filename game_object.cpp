//
// Created by Tim on 11.01.2021.
//

#include "game_object.h"

class Game_Object {

private:
    //category of the element
    char entity;
    //position
    int x;
    int y;

public:
    Game_Object(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Player : public Game_Object {

public:
    int health;
    int dps;


};


class Item : public Game_Object {

};