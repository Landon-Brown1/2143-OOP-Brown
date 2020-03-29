/*
* AUTHOR: Landon Brown
* FILE TITLE: Pokemon.hpp
* FILE DESCRIPTION: Base Pokemon class
* DUE DATE: TBD
* DATE CREATED: 03/14/2020 
*/
#include "Type.hpp"

class Pokemon{

    int dex;                // pokedex #
    string name;            // just the base name
    Type type1;             // either 1,
    Type type2;             //      or 2 types
    float weight;           // in lbs
    float height;           // in inches
    bool finalEvolution;    // bool for Reached Final Evolution
    int HP;                 // base hp
    int Attack;             // base attack
    int Defence;            // base defence
    int SpAttack;           // base special attack
    int SpDefence;          // base special defence
    int Speed;              // base speed

public:

    //--------------Constructors---------------//
    // Base (empty) constructor
    Pokemon(){
        dex = -1;
        name = "N/A";
        type1 = type2 = Type("NULL");
        weight = height = -1;
        finalEvolution = "false";
        HP = Attack = Defence = 
        SpAttack = SpDefence = Speed = -1;
    }

    // please for the love of god never use this (loaded constructor)
    Pokemon(int dx, string nam, Type one, Type two,
            float wei, float hei, bool fe,
            int hp, int at, int def, int spa,
            int spd, int spe){
        dex = dx;
        name = nam;
        type1 = one;
        type2 = two;
        weight = wei;
        height = hei;
        finalEvolution = fe;
        HP = hp;
        Attack = at;
        Defence = def;
        SpAttack = spa;
        SpDefence = spd;
        Speed = spe;
    }

    // copy constructor
    Pokemon(const Pokemon& other){
        dex = other.dex;
        name = other.name;
        type1 = other.type1;
        type2 = other.type2;
        weight = other.weight;
        height = other.height;
        finalEvolution = other.finalEvolution;
        HP = other.HP;
        Attack = other.Attack;
        Defence = other.Defence;
        SpAttack = other.SpAttack;
        SpDefence = other.SpDefence;
        Speed = other.Speed;
    }

    //Pokemon "destructor"
    ~Pokemon(){
        dex = -1;
        name = "N/A";
        type1 = type2 = Type("NULL");
        weight = height = -1;
        finalEvolution = "false";
        HP = Attack = Defence = 
        SpAttack = SpDefence = Speed = -1;
    }

    // overloaded assignment operator
    Pokemon& operator=(Pokemon& rhs){
        if(this != &rhs){
            dex = rhs.getDex();
            name = rhs.getName();
            type1 = rhs.getType1();
            type2 = rhs.getType2();
            weight = rhs.getWeight();
            height = rhs.getHeight();
            finalEvolution = rhs.getFinalEvolution();
            HP = rhs.getHP();
            Attack = rhs.getAttack();
            Defence = rhs.getDefence();
            SpAttack = rhs.getSpAttack();
            SpDefence = rhs.getSpDefence();
            Speed = rhs.getSpeed();
        }
        return *this; 
    }

    // overloaded output operator
    friend ostream& operator<<(ostream& out, const Pokemon& p){
        out << p.dex << "->" << p.name << "->" << p.type1 
            << "->" << p.type2 << "->" << p.weight << "->" 
            << p.height << "->" << p.finalEvolution << "->" 
            << p.HP << "->" << p.Attack << "->" << p.Defence 
            << "->" << p.SpAttack << "->" << p.SpDefence 
            << "->" << p.Speed << endl << endl;
        return out;
    }

    // remove a pokemon's data
    void PokeDelete(){
        dex = -1;
        name = "N/A";
        type1 = type2 = Type("NULL");
        weight = height = -1;
        finalEvolution = "false";
        HP = Attack = Defence = 
        SpAttack = SpDefence = Speed = -1;
    }

    // setters------------------------------------
    void setDex(int x){
        dex = x;
    }
    void setName(string x){
        name = x;
    }
    void setType1(Type x){
        type1 = x;
    }
    void setType2(Type x){
        type2 = x;
    }
    void setWeight(float x){
        weight = x;
    }
    void setHeight(float x){
        height = x;
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

    // getters------------------------------------
    int getDex(){
        return dex;
    }
    string getName(){
        return name;
    }
    Type getType1(){
        return type1;
    }
    Type getType2(){
        return type2;
    }
    float getWeight(){
        return weight;
    }
    float getHeight(){
        return height;
    }
    bool getFinalEvolution(){
        return finalEvolution;
    }
    int getHP(){
        return HP;
    }
    int getAttack(){
        return Attack;
    }
    int getDefence(){
        return Defence;
    }
    int getSpAttack(){
        return SpAttack;
    }
    int getSpDefence(){
        return SpDefence;
    }
    int getSpeed(){
        return Speed;
    }





};

// Individual Pokemon Classes---------------------
class Bulbasaur:public Pokemon{
    
public:
    Bulbasaur(){
        setDex(1);
        setName("Bulbasaur");
        setType1(Type("grass"));
        setType2(Type("poison"));
        setWeight(15.2);
        setHeight(28);
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
        setType1(Type("grass"));
        setType2(Type("poison"));
        setWeight(28.7);
        setHeight(39);
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
        setType1(Type("grass"));
        setType2(Type("poison"));
        setWeight(220.5);
        setHeight(75);
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
        setType1(Type("fire"));
        setType2(Type("none"));
        setWeight(18.7);
        setHeight(24);
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
        setType1(Type("fire"));
        setType2(Type("none"));
        setWeight(41.9);
        setHeight(43);
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
        setType1(Type("fire"));
        setType2(Type("flying"));
        setWeight(199.5);
        setHeight(67);
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
        setType1(Type("water"));
        setType2(Type("none"));
        setWeight(19.8);
        setHeight(20);
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
        setType1(Type("water"));
        setType2(Type("none"));
        setWeight(49.6);
        setHeight(39);
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
        setType1(Type("water"));
        setType2(Type("none"));
        setWeight(188.5);
        setHeight(63);
        setFinalEvolution(true);
        setHP(79);
        setAttack(83);
        setDefence(100);
        setSpAttack(85);
        setSpDefence(105);
        setSpeed(78);
    }
    
};