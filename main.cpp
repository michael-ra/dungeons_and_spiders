

#include "worldutil.h"
#include "world.h"
#include "enemy_goblin.h"
#include "enemy_knight.h"
#include "player.h"
#include "Knights.h"
#include "Goblins.h"
#include "Collision.h"
#include <vector>

using namespace std;

int main() {


    world w;
    generateNewWorld(w, 1);
    w.printWorld();

    int amount_goblin = 2;
    int amount_knight = 2;

    vector<Goblin *> goblins;
    vector<Knight *> knights;

    Collision new_collision = Collision();

    Knights my_knights();
    Goblins my_goblins();

    for (int i = 0; i < amount_goblin; i++) {
        Goblin *zeiger = new Goblin();
        zeiger->set_point(getRandomFreePlace(w));
        zeiger->set_point_on_map(w);
        goblins.push_back(zeiger);
    }

    for (int i = 0; i < amount_knight; i++) {
        Knight *zeiger = new Knight();
        zeiger->set_point(getRandomFreePlace(w));
        zeiger->set_point_on_map(w);
        knights.push_back(zeiger);
    }

    //same for items

    Player player = Player();
    player.set_x(0);
    player.set_y(0);
    player.set_point_on_map(w);


    string taste;

    while (taste != "x") {

        taste = spielfeld.lastKey();

        // Frage die Tasten ab
        if (taste == "ArrowUp") {
            player.up_movement(w);
            if (player.up_movement(w)) {
                char entity = w.getFields(player.get_x_point(), player.get_y_point() - 1);

                if (entity == 'g') {
                    Goblin *goblin_pointer = my_goblins().scearch_goblins(goblins, player.get_x_point(),
                                                                          player.get_y_point() - 1);

                    bool player_dead = new_collision.collision_goblin(&player, goblin_pointer, &w);
                    if (player_dead) {
                        taste = "x";
                    }
                }
                if (entity == 'k') {
                    Knight *knight_pointer = my_knights().scearch_knight(knights, player.get_x_point(),
                                                                         player.get_y_point() - 1);

                    bool player_dead = new_collision.collision_knight(&player, knight_pointer, &w);
                    if (player_dead) {
                        taste = "x";
                    }

                }

            }
        } else if (taste == "ArrowDown") {
            player.down_movement(w);
            if (player.down_movement(w)) {

                char entity = w.getFields(player.get_x_point(), player.get_y_point() + 1);

                if (entity == 'g') {
                    Goblin *goblin_pointer = my_goblins().scearch_goblins(goblins, player.get_x_point(),
                                                                          player.get_y_point() + 1);

                    bool player_dead = new_collision.collision_goblin(&player, goblin_pointer, &w);
                    if (player_dead) {
                        taste = "x";
                    }
                }
                if (entity == 'k') {
                    Knight *knight_pointer = my_knights().scearch_knight(knights, player.get_x_point(),
                                                                         player.get_y_point() + 1);

                    bool player_dead = new_collision.collision_knight(&player, knight_pointer, &w);
                    if (player_dead) {
                        taste = "x";
                    }

                }

            }
        } else if (taste == "ArrowLeft") {
            player.left_movement(w);
            if (player.left_movement(w)) {
                char entity = w.getFields(player.get_x_point() - 1, player.get_y_point());

                if (entity == 'g') {
                    Goblin *goblin_pointer = my_goblins().scearch_goblins(goblins, player.get_x_point() - 1,
                                                                          player.get_y_point());

                    bool player_dead = new_collision.collision_goblin(&player, goblin_pointer, &w);
                    if (player_dead) {
                        taste = "x";
                    }
                }
                if (entity == 'k') {
                    Knight *knight_pointer = my_knights().scearch_knight(knights, player.get_x_point() - 1,
                                                                         player.get_y_point());

                    bool player_dead = new_collision.collision_knight(&player, knight_pointer, &w);
                    if (player_dead) {
                        taste = "x";
                    }

                }
            }
        } else if (taste == "ArrowRight") {
            player.right_movement(w);
            if (player.right_movement(w)) {
                char entity = w.getFields(player.get_x_point() + 1, player.get_y_point());

                if (entity == 'g') {
                    Goblin *goblin_pointer = my_goblins().scearch_goblins(goblins, player.get_x_point() + 1,
                                                                          player.get_y_point());

                    bool player_dead = new_collision.collision_goblin(&player, goblin_pointer, &w);
                    if (player_dead) {
                        taste = "x";
                    }
                }
                if (entity == 'k') {
                    Knight *knight_pointer = my_knights().scearch_knight(knights, player.get_x_point() + 1,
                                                                         player.get_y_point());

                    bool player_dead = new_collision.collision_knight(&player, knight_pointer, &w);
                    if (player_dead) {
                        taste = "x";
                    }

                }
            }
        }
        player.set_point_on_map(w);

        for (int i = 0; i < amount_knight; i++) {
            knights.at(i)->movement(w);
            knights.at(i)->set_point_on_map(w);
        }

        for (int i = 0; i < amount_goblin; i++) {
            goblins.at(i)->movement(w);
            goblins.at(i)->set_point_on_map(w);
        }

    }

    //cancelExecution("1", "1");

    return 1;
}
