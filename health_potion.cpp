#include "health_potion.h"

void HealthPotion::increase_health(int players_health) {

    if ((players_health += potion) >= max_health) {
        players_health = max_health;
    } else {
        players_health += potion;
    }
}
