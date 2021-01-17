//
// Created by Tim on 11.01.2021.
//

#include "game_object.h"
#include "worldutil.cpp"

class Game_Object {

protected:
    //category of the element
    char entity;

    Point last_position;

    int health;
    int dps;

    int max_health;

    //position
    Point point;


public:

    Game_Object() {

    }

    Game_Object(int x, int y) {
        point.x = x;
        point.y = y;
    }

    //setter
    void set_x(int x) {
        point.x = x;
    }

    void set_y(int y) {
        point.y = y;
    }

    //getter
    int get_x_point() {
        return point.x;
    }

    int get_y_point() {
        return point.y;
    }

    Point get_point() {
        return point;
    }

};




