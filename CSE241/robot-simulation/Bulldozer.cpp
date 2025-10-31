#ifndef _BULLDOZER_
#define _BULLDOZER_

#include "Bulldozer.h"

//constructors implementations type of robot = 3
Bulldozer::Bulldozer() : Robot(3){
    /*Intentionally empty*/
}
Bulldozer::Bulldozer(int newStrength, int newHit, string name) :
    Robot(3, newStrength, newHit, name){
    
    /*Intentionally empty*/
}

//getDamage function that use base class getDamage
int Bulldozer::getDamage() const {
    return Robot::getDamage();
}

//special bulldozer getType function
string Bulldozer::getType() const {
    return "bulldozer";
}

#endif