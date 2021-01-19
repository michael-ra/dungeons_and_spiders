#include "game_object.h"

void Game_Object::set_x(int x) {
    point.x = x;
}

void Game_Object::set_y(int y) {
    point.y = y;
}

void Game_Object::set_point(Point point) {
    this->point = point;
}

void Game_Object::set_entity(char entity) {
    this->entity = entity;
}

int Game_Object::get_x_point() {
    return point.x;
}

int Game_Object::get_y_point() {
    return point.y;
}

Point Game_Object::get_point() {
    return point;
}

void Game_Object::set_point_on_map(world &w) {
    w.setFields(entity, point.x, point.y);
}

char Game_Object::get_entity() {
    return entity;
}


