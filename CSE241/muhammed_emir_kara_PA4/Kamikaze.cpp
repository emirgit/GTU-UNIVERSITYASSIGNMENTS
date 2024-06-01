#ifndef _KAMIKAZE_
#define _KAMIKAZE_

#include "Kamikaze.h"


//consturoctrs for kamikaze type of kamikaze is 4
Kamikaze::Kamikaze() : Robot(4){
    /*Intentionally empty*/
}
Kamikaze::Kamikaze(int newStrength, int newHit, string name) :
    Robot(4, newStrength, newHit, name){
    
    /*Intentionally empty*/
}

//the damage of kamikaze is as much as his hp
int Kamikaze::getDamage() const {
    int damage = getHP();
    //cout << getType() << " attacks for " << damage << " points!" << endl;
    return damage;
}

//the special getType for kamikaze
string Kamikaze::getType() const {
    return "kamikaze";
}
#endif