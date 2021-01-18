//
// Created by Tim on 12.01.2021.
//

#include "enemy_knight.h"
#include "enemy.cpp"
#include "vector"

using namespace std;

class Knight : public Enemy {

public:
    Knight() {

        dps = 5;
        health = 5;
        entity = 'k';

    }

    //O R U L !diagonal movement missing! DIAG_RL DIAG_LR
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


    //if collision/hit then dodge the player by step to the oppsite/other direction
    //wie ist hit definiert wenn player und feind nebeneinander sind und wirklich das kurz aufeinander und dann zurueck
    //Player: '#'

    void follow(world w, Point player) {

        int range = 5;
        Node pos;

        if (getDistance(w, player, point) <= range) {
            //using pathfinder (not sure if is supposed like this
            //geht das ueberhaupt mit pathfinder pathfinder(w, point, player, 2);

            Point closer = point;
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
            }
        }

    }


    /*void dodge(world w, bool hit) {

        char player = '#';
        char free_to_move = '1';
        if (hit) {
            //If Player is above
            if (world.at(0) == player) {
                //down
                if (world.at(2) == free_to_move) {
                    y = y + 1;
                } else if (world.at(1) == free_to_move) {
                    //right
                    x = x + 1;
                }
                    //left
                else if (world.at(3) == free_to_move) {
                    x = x - 1;
                }
            }
            //If Player is right
            if (world.at(1) == player) {
                if (world.at(3) == free_to_move) {
                    //left
                    x = x - 1;
                } else if (world.at(0) == free_to_move) {
                    //up
                    y = y - 1;
                } else if (world.at(2) == free_to_move) {
                    //down
                    y = y + 1;
                }

            }
            //If Player is underneath
            if (world.at(2) == player) {
                if (world.at(0) == free_to_move) {
                    //up
                    y = y - 1;
                } else if (world.at(3) == free_to_move) {
                    //left
                    x = x - 1;
                } else if (world.at(1) == free_to_move) {
                    //right
                    x = x + 1;
                }

            }
            //If Player is left
            if (world.at(3) == player) {
                if (world.at(1) == free_to_move) {
                    //right
                    x = x + 1;
                } else if (world.at(3) == free_to_move) {
                    //left
                    x = x - 1;
                } else if (world.at(0) == free_to_move) {
                    //up
                    y = y - 1;
                }
            }
        }
    }
    */
};