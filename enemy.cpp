

#include "enemy.h"

void Enemy::set_health(int health) {
    //Setter for health
    this->health = health;
}

void Enemy::set_dps(int dps) {
    //Setter for damage
    this->dps = dps;
}

int Enemy::get_health() {
    //Get the amount of health left
    return health;
}

int Enemy::get_dps() {
    //Get the damage points of the enemy
    return dps;
}

void Enemy::take_damage(int damage) {
    //reduce damage when hit
    this->health -= damage;
}

bool Enemy::is_dead() {
    if (health <= 0) {
        return true;
    } else {
        return false;
    }
}

void Enemy::do_damage(int dmg_of_player) {
    health -= dmg_of_player;
    point = last_position;
}
