//
// Created by Tim on 12.01.2021.
//

#include "enemy_knight.h"
#include "enemy.cpp"
#include "vector"

using namespace std;

class Enemy_knight : public Enemy {

public:
    Enemy_knight() {

        dps = 5;
        health = 5;

    }

    //O R U L DIAG_RL DIAG_LR
    void movement(vector<char> world) {

        char free_to_move = '1';

        if (world.at(4) == free_to_move) {
            //oben links
            y = y - 1;
            x = x - 1;
        } else if (world.at(5) == free_to_move) {
            //oben rechts
            y = y - 1;
            x = x + 1;
        } else if (world.at(6) == free_to_move) {
            //unten links
            y = y + 1;
            x = x - 1;
        } else if (world.at(7) == free_to_move) {
            //unten rechts
            y = y + 1;
            x = x + 1;
        } else if (world.at(2) == free_to_move) {
            //down
            y = y + 1;
        } else if (world.at(3) == free_to_move) {
            //left
            x = x - 1;
        } else if (world.at(0) == free_to_move) {
            //up
            y = y - 1;
        } else if (world.at(1) == free_to_move) {
            //right
            x = x + 1;
        }
    }

    //if collision/hit then dodge the player by step to the oppsite/other direction
    //wie ist hit definiert wenn player und feind nebeneinander sind und wirklich das kurz aufeinander und dann zurueck
    //Player: '#'
    void dodge(vector<char> world, bool hit) {

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

};