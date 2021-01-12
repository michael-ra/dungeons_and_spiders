//
// Created by Tim on 12.01.2021.
//

#include "enemy_knight.h"
#include "enemy.cpp"
#include "vector"

using namespace std;

class Enemy_knight {

    Enemy_knight() {

        dps = 5;
        health = 5;

    }

    void movement(vector<char> world) {

        if (world.at(0) == '4') {
            y = y - 1;
        } else if (world.at(1) == '5') {
            x = x + 1;
        } else if (world.at(2) == '1') {
            y = y + 1;
        } else if (world.at(3) == '1') {
            x = x - 1;
        } else if (world.at(0) == '1') {
            y = y - 1;
        } else if (world.at(1) == '1') {
            x = x + 1;
        }
    }

};