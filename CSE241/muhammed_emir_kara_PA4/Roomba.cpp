#ifndef _ROOMBA_
#define _ROOMBA_

#include "Roomba.h"

//constructors 
Roomba::Roomba() : Robot(2){
    /*Intentionally empty*/
}

Roomba::Roomba(int newStrength, int newHit, string name) :
    Robot(2,newStrength, newHit, name){
    
    /*Intentionally empty*/
}

// get damage function that used robot's get damage twice
int Roomba::getDamage() const {
    int damage1 = Robot::getDamage();
    int damage2 = Robot::getDamage();

    return damage1 + damage2;
}

//special get damage for roomba
string Roomba::getType() const {
    return "roomba";
}
#endif