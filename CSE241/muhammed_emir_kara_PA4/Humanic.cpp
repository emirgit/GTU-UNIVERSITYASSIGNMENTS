#ifndef _HUMANIC_
#define _HUMANIC_

#include "Humanic.h"

//constructors 
Humanic::Humanic(int type = -1) : Robot(type){
    /*Intentionally empty*/
}
Humanic::Humanic(int newType, int newStrength, int newHit, string name):
    Robot(newType, newStrength, newHit, name){
    
    /*Intentionally empty*/
}

//get damage function that use robot's get damage and after add the nuke damage based on prob.
int Humanic::getDamage() const {
    int damage = Robot::getDamage(); // Call base class function

    // Humanic specific damage calculation
    if (rand() % 10 == 0) { // 10% chance of tactical nuke
        damage += 50;
        //cout << "Tactical Nuke! Additional 50 damage points!" << endl;
    }

    return damage;
}

//optimus prime and robocop is humanic robots the type unknown return "unknown"
string Humanic::getType() const {

    switch (type){
        case 0: 
            return "optimusprime";
        case 1:
            return "robocop";
    }

    return "unknown";
}
#endif