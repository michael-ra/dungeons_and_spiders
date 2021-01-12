//
// Created by Tim on 11.01.2021.
//

#include "game_object.h"

class Game_Object {

protected:
    //category of the element
    char entity;
    //position
    int x;
    int y;


public:

    Game_Object() {

    }

    Game_Object(int x, int y) {
        this->x = x;
        this->y = y;
    }
};




class Item : public Game_Object {

};