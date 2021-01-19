#include "item.h"
void Item::set_additional_health(int health) {
    //Setter for health
    this->health = health;
}

void Item::set_additional_dps(int dps) {
    //Setter for damage
    this->dps = dps;
}

int Item::get_additional_health() {
    //Get the amount of health left
    return health;
}

int Item::get_additional_dps() {
    //Get the damage points of the enemy
    return dps;
}
