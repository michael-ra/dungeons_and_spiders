//
// Created by Tim on 19.01.2021.
//

#ifndef DUNGEONCRAWLER_COLLISION_H
#define DUNGEONCRAWLER_COLLISION_H

#include "enemy_knight.h"
#include "enemy_goblin.h"
#include "game_object.h"
#include "player.h"
#include "world.h"
#include "health_potion.h"

class Collision {

public:

    bool collision_knight(Player *player, Knight *knight, world *world) {

        knight->do_damage(player->dps);
        player->damage(knight->dps);

        if (knight->is_dead()) {
            world->setFields('f', knight->get_x_point(), knight->get_y_point());
            delete knight;
        }
        if (player->dead()) {
            return true;
        }
        return false;
    }

    bool collision_goblin(Player *player, Goblin *goblin, world *world) {

        goblin->do_damage(player->dps);
        player->damage(goblin->dps);

        if (goblin->is_dead()) {
            world->setFields('f', goblin->get_x_point(), goblin->get_y_point());
            delete goblin;
        }
        if (player->dead()) {
            return true;
        }
        return false;

    }

    void collision_health_potion(Player *player, HealthPotion *health_potion, world *world) {

        player->increase_health(health_potion->get_potion_size());
        world->setFields('f', health_potion->get_x_point(), health_potion->get_y_point());
        delete health_potion;

    }
};


#endif //DUNGEONCRAWLER_COLLISION_H
