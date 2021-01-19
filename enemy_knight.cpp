#include "enemy_knight.h"

void Knight::movement(world &w) {

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
    else if (movements[2] == 0) {
        last_position = point;
        point.y = point.y + 1;
    }
}

void Knight::follow(world w, Point player) {

    int range = 5;
    Node pos;

    if (getDistance(w, player, point) <= range) {
        //using pathfinder (not sure if is supposed like this
        //geht das ueberhaupt mit pathfinder pathfinder(w, point, player, 2);

        switch (pathfinder(w, point, player, 2)) {
            //0: O, 1: R, 2: U, 3: L
            case 0:
                last_position = point;
                point.y = point.y - 1;
                break;
            case 1:
                last_position = point;
                point.x = point.x + 1;
                break;
            case 2:
                last_position = point;
                point.y = point.y + 1;
                break;
            case 3:
                last_position = point;
                point.x = point.x - 1;
                break;
        }


        /* Point closer = point;
         closer.x += 1;
         bool helper = true;
         if (getDistance(w, player, point) <= getDistance(w, player, point) && checkFree(w, closer)) {
             point = closer;
             helper = false;
         }
         closer.x -= 1;
         if (helper && getDistance(w, player, point) <= getDistance(w, player, point) && checkFree(w, closer)) {
             point = closer;
             helper = false;
         }
         closer.y += 1;
         if (helper && getDistance(w, player, point) <= getDistance(w, player, point) && checkFree(w, closer)) {
             point = closer;
             helper = false;
         }
         closer.y -= 1;
         if (helper && getDistance(w, player, point) <= getDistance(w, player, point) && checkFree(w, closer)) {
             point = closer;
             helper = false;
         }*/
    }
}
