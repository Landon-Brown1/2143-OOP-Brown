/*
* AUTHOR: Landon Brown
* FILE TITLE: Party.hpp
* FILE DESCRIPTION: Pokemon party object class
* DUE DATE: TBD
* DATE CREATED: 03/23/2020 
*/

#include "Pokemon.hpp"

const int MAX_PARTY_SIZE = 6;

class Party{
    Pokemon party[MAX_PARTY_SIZE];  //party of 6
    int size;                       //size of party
    int first;                      //first pokemon to be sent out

public:

    //--------------Constructors---------------//
    // Base (empty) constructor
    Party(){
        size = 0;
        first = 0;
        Pokemon p;
        for(int i = 0; i < MAX_PARTY_SIZE; i++){
            party[i] = p;
        }
    }

    // Loaded Constructor
    Party(int s, Pokemon p[MAX_PARTY_SIZE], int f){
        if(s <= 6 && s >= 0)
            size = s;
        if(f <= s && f >= 0)
            first = f;
        for(int i = 0; i < MAX_PARTY_SIZE; i++){
            party[i] = p[i];
        }
    }

    // Copy Constructor
    Party(Party& other){
        size = other.size;
        first = other.first;
        for(int i = 0; i < other.size; i++)
            party[i] = other.party[i];
    }

    // Overloaded assignment operator
    Party& operator=(const Party& rhs){
        if(this != &rhs){
            for(int i = 0; i < this->size; i++)
                removePokemon(i);
            for(int i = 0; i < rhs.size; i++)
                addPokemon(rhs.party[i]);
            this->first = rhs.first;
            return *this;
        }
        
    }
    // setters------------------------------------
    void setSize(int x){
        if(x <= 6 && x >= 0)
            size = x;
    }
    
    void setFirst(int x){
        if(x <= size && x >= 0)
            first = x;
    }

    // getters------------------------------------
    int getSize(){
        return size;
    }

    int getFirst(){
        return first;
    }

    // Add or Remove a pokemon from the party-----
    void addPokemon(Pokemon x){
        if(size < 6){
            party[size] = x;
            size++;
        }
    }

    Pokemon& removePokemon(int position){
        Pokemon p;
        if(position <= 6 && position >= 0){
            p = party[position];
            party[position].PokeDelete();
            size--;
        }
        return p;
    }


};