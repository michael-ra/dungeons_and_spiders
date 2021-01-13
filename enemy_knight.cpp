//
// Created by Tim on 12.01.2021.
//

#include "enemy_knight.h"
#include "enemy.cpp"
#include "vector"

using namespace std;

class Enemy_knight : public Enemy {

    Enemy_knight() {

        dps = 5;
        health = 5;

    }

    void movement(vector<char> world) {

        //Micha: diag_rl, diag_lr > sind double vectors/arrays wieder
        //nicht ganz sicher bei der Umsetzung erstmal einen Vector mit {x,x,x,x,c,c,c,c} angenommen
        if (world.at(4) == '1') {
            //oben links
            y = y - 1;
            x = x - 1;
        } else if (world.at(5) == '1') {
            //oben rechts
            y = y - 1;
            x = x + 1;
        } else if (world.at(5) == '1') {
            //unten links
            y = y + 1;
            x = x - 1;
        } else if (world.at(5) == '1') {
            //unten rechts
            y = y + 1;
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