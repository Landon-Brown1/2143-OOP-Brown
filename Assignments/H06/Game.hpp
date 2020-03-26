/*
* AUTHOR: Landon Brown
* FILE TITLE: Game.hpp
* FILE DESCRIPTION: Build a Pokémon game class. The main function
*   of this game is to serve as a Pokémon battle simulation.
* DUE DATE: TBD
* DATE CREATED: 03/14/2020 
*/

#include <iostream>
#include "Battle.hpp"
#include "Menu.hpp"

using namespace std;

class Game{
    private:
        Battle b;
        Menu m;

    public:
        Game(){
            
        }


        void run(){
            m.printIntro();
        }

};