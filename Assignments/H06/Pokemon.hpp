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

    int dex;                // pokedex #
    string name;            // just the base name
    Type type[NUM_TYPES];   // either 1 or 2 types
    float weight;           // in lbs
    float height;           // in inches
    char gender;            // only Male for now
    bool finalEvolution;    // bool for Reached Final Evolution
    int HP;                 // base hp
    int Attack;             // base attack
    int Defence;            // base defence
    int SpAttack;           // base special attack
    int SpDefence;          // base special defence
    int Speed;              // base speed

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
        setDex(1);
        setName("Bulbasaur");
        Type t[NUM_TYPES];
        t[0].setName("grass");
        t[1].setName("poison");
        setType(t);
        setWeight(15.2);
        setHeight(28);
        setGender('M');
        setFinalEvolution(false);
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
        setDex(2);
        setName("Ivysaur");
        Type t[NUM_TYPES];
        t[0].setName("grass");
        t[1].setName("poison");
        setType(t);
        setWeight(28.7);
        setHeight(39);
        setGender('M');
        setFinalEvolution(false);
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
        setDex(3);
        setName("Venusaur");
        Type t[NUM_TYPES];
        t[0].setName("grass");
        t[1].setName("poison");
        setType(t);
        setWeight(220.5);
        setHeight(75);
        setGender('M');
        setFinalEvolution(true);
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
        setDex(4);
        setName("Charmander");
        Type t[NUM_TYPES];
        t[0].setName("fire");
        t[1].setName("none");
        setType(t);
        setWeight(18.7);
        setHeight(24);
        setGender('M');
        setFinalEvolution(false);
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
        setDex(5);
        setName("Charmeleon");
        Type t[NUM_TYPES];
        t[0].setName("fire");
        t[1].setName("none");
        setType(t);
        setWeight(41.9);
        setHeight(43);
        setGender('M');
        setFinalEvolution(false);
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
        setDex(6);
        setName("Charizard");
        Type t[NUM_TYPES];
        t[0].setName("fire");
        t[1].setName("flying");
        setType(t);
        setWeight(199.5);
        setHeight(67);
        setGender('M');
        setFinalEvolution(true);
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
        setDex(7);
        setName("Squirtle");
        Type t[NUM_TYPES];
        t[0].setName("water");
        t[1].setName("none");
        setType(t);
        setWeight(19.8);
        setHeight(20);
        setGender('M');
        setFinalEvolution(false);
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
        setDex(8);
        setName("Wartortle");
        Type t[NUM_TYPES];
        t[0].setName("water");
        t[1].setName("none");
        setType(t);
        setWeight(49.6);
        setHeight(39);
        setGender('M');
        setFinalEvolution(false);
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
        setDex(4);
        setName("Blastoise");
        Type t[NUM_TYPES];
        t[0].setName("water");
        t[1].setName("none");
        setType(t);
        setWeight(188.5);
        setHeight(63);
        setGender('M');
        setFinalEvolution(true);
        setHP(79);
        setAttack(83);
        setDefence(100);
        setSpAttack(85);
        setSpDefence(105);
        setSpeed(78);
    }
    
};