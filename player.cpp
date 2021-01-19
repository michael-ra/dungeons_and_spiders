#include "player.h"

bool Player::down_movement(world &w) {
    Point p = point;
    last_position = point;
    p.y += 1;
    if (checkFree(w, p)) {
        point.y += 1;
    } else if (w.is_object(w, p.x, p.y)) {
        return true;
    }
    return false;
}

bool Player::up_movement(world &w) {
    Point p = point;
    last_position = point;
    p.y -= 1;
    if (checkFree(w, p)) {
        point.y -= 1;
    } else if (w.is_object(w, p.x, p.y)) {
        return true;
    }
    return false;
}

bool Player::left_movement(world &w) {
    Point p = point;
    last_position = point;
    p.x -= 1;
    if (checkFree(w, p)) {
        point.x -= 1;
    } else if (w.is_object(w, p.x, p.y)) {
        return true;
    }
    return false;
}

bool Player::right_movement(world &w) {
    Point p = point;
    last_position = point;
    p.x += 1;
    if (checkFree(w, p)) {
        point.x += 1;
    } else if (w.is_object(w, p.x, p.y)) {
        return true;
    }
    return false;
}

void Player::set_health(int health) {
    if (health >= 0) {
        this->health = health;
    }
}

void Player::set_dps(int dps) {
    if (dps >= 0) {
        this->dps = dps;
    }
}

int Player::get_health() {
    return health;
}

int Player::get_dps() {
    return dps;
}

void Player::damage(int dps_of_enemy) {
    health -= dps_of_enemy;
    point = last_position;
}

bool Player::dead() {
    if (health <= 0) {
        return true;
    }
    return false;
}
