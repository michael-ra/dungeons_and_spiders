//
// Created by Tim on 11.01.2021.
//

#include "game_object.h"
#include "worldutil.cpp"


class Game_Object {

protected:
    //category of the element
    char entity;

    //point before the last movement/step
    Point last_position;

    //Game_Object Attributes
    int health;
    int max_health;
    int dps;

    //Position
    Point point;

    world w;

public:

    Game_Object() {
        entity = 'g';

    }

    Game_Object(int x, int y) {
        point.x = x;
        point.y = y;
        entity = 'g';
    }

    //setter
    void set_x(int x) {
        point.x = x;
    }

    void set_y(int y) {
        point.y = y;
    }

    void set_point(Point point) {
        this->point = point;
    }

    void set_entity(char entity) {
        this->entity = entity;
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

    void set_point_on_map(world &w) {
        w.setFields(entity, point.x, point.y);
    }

    char get_entity() {
        return entity;
    }


};




