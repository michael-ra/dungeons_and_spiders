

#include "worldutil.cpp"
#include "enemy_goblin.cpp"
#include "enemy_knight.cpp"
#include "player.cpp"
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
                if (w.getFields(player.get_x_point(), player.get_y_point() - 1)) {

                }


            }
        } else if (taste == "ArrowDown") {
            player.down_movement(w);
        } else if (taste == "ArrowLeft") {
            player.left_movement(w);
        } else if (taste == "ArrowRight") {
            player.right_movement(w);
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


    return 1;
}
