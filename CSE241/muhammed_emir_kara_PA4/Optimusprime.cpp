#ifndef _OPTIMUSPRIME_
#define _OPTIMUSPRIME_

#include "Optimusprime.h"

//optimus prime construcotr type of optimusprime is 0
Optimusprime::Optimusprime() : Humanic(0){
    /*Intentionally empty*/
}
Optimusprime::Optimusprime(int newStrength, int newHit, string name) :
    Humanic(0, newStrength, newHit, name){
    
    /*Intentionally empty*/
}

//getDamage function call humanics getDamage and humanic getDamage invoke robot getdamage
int Optimusprime::getDamage() const {
    int damage = Humanic::getDamage(); 

    if (rand() % 20 < 3) {
        damage *= 2;
        //cout << "Strong Attack! Damage doubled!" << endl;
    }

    return damage;
}

//special getType function of optimusprime
string Optimusprime::getType() const {
    return "optimusprime";
}

#endif