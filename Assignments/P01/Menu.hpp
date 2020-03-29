/*
* AUTHOR: Landon Brown
* FILE TITLE: Menu.hpp
* FILE DESCRIPTION: Menu for the beginning of the game
* DUE DATE: TBD
* DATE CREATED: 03/26/2020
*/
#include <iostream>
#include <string>

using namespace std; 

struct Menu{

    Menu(){
        
    }

    void printIntro(){
        cout << endl << "     @@----------------------------------------------------@@     " << endl
                     << "   @@    Welcome to  Pokemon: Brown Version!                 @@   " << endl
                     << " @@      If you would like to play, please press 'y'.          @@ " << endl
                     << "((                                                              ))" << endl
                     << " @@                                                            @@ " << endl
                     << "   @@                                                        @@   " << endl
                     << "     @@----------------------------------------------------@@     " << endl;
    }

    void firstSelect(){
        cout << endl << "     @@----------------------------------------------------@@     " << endl
                     << "   @@    Player One, please select your Pokemon by typing    @@   " << endl
                     << " @@      The respective Pokedex number of each Pokemon         @@ " << endl
                     << "((       you would like in your party (up to 6). The first      ))" << endl
                     << " @@      Pokemon you choose will be the first in your          @@ " << endl
                     << "   @@    lineup to be sent to battle!                        @@   " << endl
                     << "     @@----------------------------------------------------@@     " << endl;
    }
    void secondSelect(){
        cout << endl << "     @@----------------------------------------------------@@     " << endl
                     << "   @@                                                        @@   " << endl
                     << " @@                                                            @@ " << endl
                     << "((                                                              ))" << endl
                     << " @@                                                            @@ " << endl
                     << "   @@                                                        @@   " << endl
                     << "     @@----------------------------------------------------@@     " << endl;
    }

};