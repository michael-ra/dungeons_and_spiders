//
// Created by Tim on 11.01.2021.
//

#ifndef DUNGEONCRAWLER_GAME_OBJECT_H
#define DUNGEONCRAWLER_GAME_OBJECT_H

//
// Created by Tim on 11.01.2021.
//



#include "worldutil.h"


class Game_Object {

protected:
    //category of the element
    char entity;

    //Game_Object Attributes
    int health;
    int max_health;
    int dps;

    //Position
    Point point;

    //point before the last movement/step
    Point last_position;

    //Current world
    world w;

public:

    Game_Object() {

    }

    Game_Object(int x, int y) {
        point.x = x;
        point.y = y;

    }

    //setter
    void set_x(int x);

    void set_y(int y);

    void set_point(Point point);

    void set_entity(char entity);

    //getter
    int get_x_point();

    int get_y_point();

    Point get_point();

    void set_point_on_map(world &w);

    char get_entity();

};

#endif //DUNGEONCRAWLER_GAME_OBJECT_H
