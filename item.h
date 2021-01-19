//
// Created by Tim on 13.01.2021.
//

#ifndef DUNGEONCRAWLER_ITEM_H
#define DUNGEONCRAWLER_ITEM_H


//
// Created by Tim on 13.01.2021.
//



#include "game_object.h"

class Item : public Game_Object {

    //Armor einfach mehr leben oder extra speciales
    //und macht das so sinn weil dann ja enemy und item recht identisch sind und ob man item nicht unterklasse von enemy macht
protected:

    int potion;

    Item() {

    }

    //Setter

    void set_additional_health(int health);

    void set_additional_dps(int dps);

    //Getter

    int get_additional_health();

    int get_additional_dps();

};


#endif //DUNGEONCRAWLER_ITEM_H
