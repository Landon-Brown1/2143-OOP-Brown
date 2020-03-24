/*
* AUTHOR: Landon Brown
* FILE TITLE: Pokemon.hpp
* FILE DESCRIPTION: Base Pokemon class
* DUE DATE: TBD
* DATE CREATED: 03/14/2020 
*/
#include "Type.hpp"
#include <string>

using namespace std;

const int NUM_TYPES = 2;

class Pokemon{

    int dex;
    string name;
    Type type[NUM_TYPES];
    float weight;
    float height;
    char gender;
    bool finalEvolution;
    int HP;
    int Attack;
    int Defence;
    int SpAttack;
    int SpDefence;
    int Speed;

public:

    //setters------------------------------------
    void setDex(int x){
        dex = x;
    }
    void setName(string x){
        name = x;
    }
    void setType(Type x[]){
        type[0] = x[0];
        type[1] = x[1];
    }
    void setWeight(float x){
        weight = x;
    }
    void setHeight(float x){
        height = x;
    }
    void setGender(char x){
        gender = x;
    }
    void setFinalEvolution(bool x){
        finalEvolution = x;
    }
    void setHP(int x){
        HP = x;
    }
    void setAttack(int x){
        Attack = x;
    }
    void setDefence(int x){
        Defence = x;
    }
    void setSpAttack(int x){
        SpAttack = x;
    }
    void setSpDefence(int x){
        SpDefence = x;
    }
    void setSpeed(int x){
        Speed = x;
    }

    //getters------------------------------------
    int getDex(){
        return dex;
    }
    string getName(){
        return name;
    }
    Type getType(){
        return type[NUM_TYPES];
    }
    int getDex(){
        return dex;
    }
    int getDex(){
        return dex;
    }
    int getDex(){
        return dex;
    }
    int getDex(){
        return dex;
    }
    int getDex(){
        return dex;
    }
    int getDex(){
        return dex;
    }

};

//Individual Pokemon Classes---------------------
class Bulbasaur:public Pokemon{
    
public:
    Bulbasaur(){
        setHP(45);
        setAttack(49);
        setDefence(49);
        setSpAttack(65);
        setSpDefence(65);
        setSpeed(45);
    }

};

class Ivysaur:public Pokemon{
    
public:
    Ivysaur(){
        setHP(60);
        setAttack(62);
        setDefence(63);
        setSpAttack(80);
        setSpDefence(80);
        setSpeed(60);
    }
    
};

class Venusaur:public Pokemon{
    
public:
    Venusaur(){
        setHP(80);
        setAttack(82);
        setDefence(83);
        setSpAttack(100);
        setSpDefence(100);
        setSpeed(80);
    }
    
};

class Charmander:public Pokemon{
    
public:
    Charmander(){
        setHP(39);
        setAttack(52);
        setDefence(43);
        setSpAttack(60);
        setSpDefence(50);
        setSpeed(65);
    }
    
};

class Charmeleon:public Pokemon{
    
public:
    Charmeleon(){
        setHP(58);
        setAttack(64);
        setDefence(58);
        setSpAttack(80);
        setSpDefence(65);
        setSpeed(80);
    }
    
};

class Charizard:public Pokemon{
    
public:
    Charizard(){
        setHP(78);
        setAttack(84);
        setDefence(78);
        setSpAttack(109);
        setSpDefence(85);
        setSpeed(100);
    }
    
};

class Squirtle:public Pokemon{
    
public:
    Squirtle(){
        setHP(44);
        setAttack(48);
        setDefence(65);
        setSpAttack(50);
        setSpDefence(64);
        setSpeed(43);
    }
    
};

class Wartortle:public Pokemon{
    
public:
    Wartortle(){
        setHP(59);
        setAttack(63);
        setDefence(80);
        setSpAttack(65);
        setSpDefence(80);
        setSpeed(58);
    }
    
};

class Blastoise:public Pokemon{
    
public:
    Blastoise(){
        setHP(79);
        setAttack(83);
        setDefence(100);
        setSpAttack(85);
        setSpDefence(105);
        setSpeed(78);
    }
    
};