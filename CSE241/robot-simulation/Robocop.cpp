#ifndef _ROBOCOP_
#define _ROBOCOP_

#include "Robocop.h"

//the constructors of robocop and the type of roobcop is 1
Robocop::Robocop() : Humanic(1){
    /*Intentionally empty*/
}
Robocop::Robocop(int newStrength, int newHit, string name) :
    Humanic(1, newStrength, newHit, name){
    
    /*Intentionally empty*/
}

//it just use humanic get damage
int Robocop::getDamage() const {
    return Humanic::getDamage();
}

//special getType for robocop
string Robocop::getType() const {
    return "robocop";
}
#endif