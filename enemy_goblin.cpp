#include "enemy_goblin.h"

void Goblin::movement(world &w) {

    vector<int> movements = giveMoveableSpots(w, point);
    //Left
    if (movements[3] == 0) {
        last_position = point;
        point.x = point.x - 1;
    }
        //Top
    else if (movements[0] == 0) {
        last_position = point;
        point.y = point.y - 1;
    }
        //Right
    else if (movements[1] == 0) {
        last_position = point;
        point.x = point.x + 1;
    }
        //Down
    else if (movements[3] == 0) {
        last_position = point;
        point.y = point.y + 1;
    }
}
