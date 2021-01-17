//
// Created by Tim on 12.01.2021.
//

#include "enemy_goblin.h"
#include "enemy.cpp"
#include <vector>

using namespace std;


class Goblin : public Enemy {

public:

    Goblin() {
        health = 10;
        dps = 2;
        entity = 'g';
    }

    void movement(world &w) {

        vector<int> movements = giveMoveableSpots(w, point);
        //Left
        if (movements[0] == 0) {
            last_position = point;
            point.x = point.x - 1;
        }
            //Top
        else if (movements[1] == 0) {
            last_position = point;
            point.y = point.y - 1;
        }
            //Right
        else if (movements[2] == 0) {
            last_position = point;
            point.x = point.x + 1;
        }
            //Down
        else if (movements[3] == 0) {
            last_position = point;
            point.y = point.y + 1;
        }
    }
};

