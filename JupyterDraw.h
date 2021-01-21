//
// Created by matis on 21.01.2021.
//

#ifndef GAME_JUPYTERDRAW_H
#define GAME_JUPYTERDRAW_H


#include <algoviz/SVG.hpp>
#include <string>
using namespace std;

class JupyterDraw{


    //Atributes
private:
    int mapLength = 30;
    int mapHeight = 30;
    int sideShift = 10;
    int heightShift = 0;
    char map [30][30];
    SVG svg = SVG(750,750, 10, 9);

    vector<Image*> images;
    Image *imgPointer = nullptr;


    int health = 0;
    int dmg = 0;
    int score = 0;

    string SHealth;
    string SDmg;
    string SScore;

    Rect GUI;
    Rect Final;

    Text TScore;
    Text TDmg;
    Text THealth;

    Text TFinal;


public:

    JupyterDraw(char array[30][30]){

        //save the array
        for(int i = 0; i < mapLength; i++){
            for(int j = 0; j < mapHeight; j++){
                map[i][j] = array[i][j];
            }
        }

    }




    //generates a map
    void drawMap(){
        for(int i = 0; i < mapLength; i++){
            for(int j = 0; j < mapHeight; j++){
                charToImg(map[j][i], i ,j);
            }
        }
    }

    //updates only changed blockes
    void updateMap(char curMap[30][30]){
        for(int i = 0; i < mapLength; i++){
            for(int j = 0; j < mapHeight; j++){
                if(map[j][i] != curMap[j][i]){
                    charToImg(curMap[j][i], i, j);
                    map[j][i] = curMap[j][i];
                }
            }
        }
    }

    //prints a texture according to given char (i and j = shift in x/y axis)
    //w = wall
    //o = empty space
    //c = character
    //e = enemy
    //x = exit
    //a = entrance
    //f = finder
    void charToImg(char charInArray, int i, int j){
        if(charInArray == 'w'){
            imgPointer = new Image("img/wall.png",sideShift + i*25,heightShift + j*25,25,25,&svg);
            images.push_back(imgPointer);
        }

        if(charInArray == 'o'){
            imgPointer = new Image("img/floor.png",sideShift + i*25,heightShift + j*25,25,25,&svg);
            images.push_back(imgPointer);
        }

        if(charInArray == 'c'){
            imgPointer = new Image("img/character.png",sideShift + i*25,heightShift + j*25,25,25,&svg);
            images.push_back(imgPointer);
        }

        if(charInArray == 'e'){
            imgPointer = new Image("img/enemy.png",sideShift + i*25,heightShift + j*25,25,25,&svg);
            images.push_back(imgPointer);
        }

        if(charInArray == 'x'){
            imgPointer = new Image("img/exit.png",sideShift + i*25,heightShift + j*25,25,25,&svg);
            images.push_back(imgPointer);
        }

        if(charInArray == 'a'){
            imgPointer = new Image("img/entrance.png",sideShift + i*25,heightShift + j*25,25,25,&svg);
            images.push_back(imgPointer);
        }

        if(charInArray == 'f'){
            imgPointer = new Image("img/finder.png",sideShift + i*25,heightShift + j*25,25,25,&svg);
            images.push_back(imgPointer);
        }
    }

    //draws GUI
    void drawGUI(){
        GUI = Rect(0, 739, 747, 50, &svg);
        GUI.setAttribute("fill","white");

        SHealth = "HP: " + to_string(health);
        SDmg = "DMG: " + to_string(dmg);
        SScore = "Score: " + to_string(score);

        THealth = Text(SHealth, 30, 770, &svg);
        TDmg = Text(SDmg, 330, 770, &svg);
        TScore = Text(SScore, 630, 770, &svg);

    }
    //Updates GUI Values  (HP, DMG, POINTS)
    void updateGUI(int hp, int damage, int points){
        SHealth = "HP: " + to_string(hp);
        SDmg = "DMG: " + to_string(damage);
        SScore = "Score: " + to_string(points);

        THealth.setText(SHealth);
        TDmg.setText(SDmg);
        TScore.setText(SScore);
    }

    //shows victory screen
    void victory(){
        Final = Rect(123, 188, 500, 350, &svg);
        Final.setAttribute("fill","green");
        TFinal = Text("VICTORY!", 340, 360, &svg);
    }

    //shows defeat screen
    void defeat(){
        Final = Rect(123, 188, 500, 350, &svg);
        Final.setAttribute("fill","red");
        TFinal = Text("DEFEAT!", 340, 360, &svg);
    }
};


#endif //GAME_JUPYTERDRAW_H
