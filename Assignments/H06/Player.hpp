/*
* AUTHOR: Landon Brown
* FILE TITLE: Player.hpp
* FILE DESCRIPTION: Player class
* DUE DATE: TBD
* DATE CREATED: 03/23/2020 
*/

#include "Party.hpp"

class Player{
    string name;
    Party PlayerParty;

public:

    //--------------Constructors---------------//
    // Base (empty) constructor
    Player(){
        name = "N/A";
        Party p;
        PlayerParty = p;
    }

    // Loaded Constructor
    Player(string n, Party p){
        name = n;
        PlayerParty = p;
    }

    // Copy Constructor
    Player(Player& other){
        this->name = other.name;
        this->PlayerParty = other.PlayerParty;
    }

    // Overloaded assignment operator
    Player& operator=(Player& rhs){
        this->name = rhs.name;
        this->PlayerParty = rhs.PlayerParty;
    }

    // Set Player Name
    void setName(string n){
        name = n;
    }

    // Get Player Name
    string getName(){
        return name;
    }

    // Access PC to switch out Pokemon Party
    void EditParty(){
        
    }
};