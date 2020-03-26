/*
* AUTHOR: Landon Brown
* FILE TITLE: PC.hpp
* FILE DESCRIPTION: pokemon PC class
* DUE DATE: TBD
* DATE CREATED: 03/23/2020 
*/

#include "Pokemon.hpp"
#include <fstream>

const int DEX_SIZE = 151;

struct PC{

    Pokemon list[DEX_SIZE];     //a PC is a Pokemon array;
                                //it holds all of the original 151
                                //pokemon and their information in
                                //a file.
    
    //--------------Constructors---------------//
    //base PC constructor; creates and loads a PC with the 
    //      original 151 pokemon, pulled from "pokemonlist.txt"
    PC(){
        int dx;
        string nam;
        string one;
        string two;
        float wei;
        float hei;
        bool fe;
        int hp;
        int at;
        int def;
        int spa;
        int spd;
        int spe;
        ifstream inData;
        inData.open("pokemonlist.txt");
        for(int i = 0; i < DEX_SIZE; i++){
            inData >> dx >> nam >> one >> two
                   >> wei >> hei >> fe >> hp
                   >> at >> def >> spa >> spd >> spe;
            Pokemon p(dx, nam, one, two, wei,
                      hei, fe, hp, at,
                      def, spa, spd, spe);
            list[i] = p;
        }
        inData.close();
    }

    //loaded constructor
    PC(Pokemon p[DEX_SIZE]){
        for(int i = 0; i < DEX_SIZE; i++){
            list[i] = p[i];
        }
    }

    //copy constructor
    PC(PC& other){
        for(int i = 0; i < DEX_SIZE; i++){
            this->list[i] = other.list[i];
        }
    }

    //overloaded assignment operator
    PC& operator=(PC& rhs){
        if(this != &rhs){
            for(int i = 0; i < DEX_SIZE; i++){
                this->list[i] = rhs.list[i];
            }
        }
        return *this;
    }

    void print(){
        ofstream outFile;
        outFile.open("duh.txt");
        for(int i = 0; i < DEX_SIZE; i++){
            outFile << list[i];
        }
        outFile.close();
    }
};
