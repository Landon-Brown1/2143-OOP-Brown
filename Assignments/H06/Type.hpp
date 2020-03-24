/*
* AUTHOR: Landon Brown
* FILE TITLE: Type.hpp
* FILE DESCRIPTION: Pokemon/Move type class
* DUE DATE: TBD
* DATE CREATED: 03/23/2020 
*/

#include <string>

using namespace std;

class Type{
    string name;
    
public:
    Type(){
        name = "NULL";
    }
    Type(string t1){
        name = t1;
    }

    void setName(string x){
        name = x;
    }
    string getName(){
        return name;
    }

};

class BugClass:public Type{

    

};

class DragonClass:public Type{

};

class ElectricClass:public Type{

};

class FightingClass:public Type{

};

class FireClass:public Type{

};

class FlyingClass:public Type{

};

class GhostClass:public Type{

};

class GrassClass:public Type{

};

class GroundClass:public Type{

};

class IceClass:public Type{

};

class NormalClass:public Type{

};

class PoisonClass:public Type{

};

class PsychicClass:public Type{

};

class RockClass:public Type{

};

class WaterClass:public Type{

};