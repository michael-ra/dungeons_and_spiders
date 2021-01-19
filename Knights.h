//
// Created by Tim on 19.01.2021.
//

#ifndef DUNGEONCRAWLER_KNIGHTS_H
#define DUNGEONCRAWLER_KNIGHTS_H

#include "enemy_knight.h"

class Knights {

public:

    Knight *scearch_knight(vector<Knight *> knights, int x, int y) {
        for (int i = 0; i < knights.size(); i++) {

            if (knights.at(i)->get_x_point() == x &&
                knights.at(i)->get_y_point() == y) {
                return knights.at(i);
            }
        }
    }

};


#endif //DUNGEONCRAWLER_KNIGHTS_H
