/*
* AUTHOR: Landon Brown
* FILE TITLE: main.cpp
* FILE DESCRIPTION: main file to run the program.
* DUE DATE: TBD
* DATE CREATED: 03/24/2020 
*/

#include <iostream>

using namespace std;

char map[10][20] = {"########      #####",
                    "#  ****           #",  
                    "#  ****       #####",
                    "#  ****           #",
                    "####_____         #",
                    "#           ******#",
                    "#           ******#",
                    "##_____######    ##",
                    "#                 #",
                    "###########     ###"};

const int GAME_SPEED = 100;
const int level = 1;

int main(){

    bool stopgame = false;
    int health = 100;

    while(stopgame == false && level == 1){
        system("cls");

        for(int y = 0; y < 10; y++){
            cout << map[y] << endl;
        }
        cout << "Health: " << health << "\n\n" << endl;

        for(int y = 0; y < 10; y++){
            for(int x = 0; x < 20; x++){
                switch(map[y][x]){
                    case '#': map[y][x] = '#';
                              break;
                    case '*': map[y][x] = '*';
                              break;

                }
            }
        }
    }


}