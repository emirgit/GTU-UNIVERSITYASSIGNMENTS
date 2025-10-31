#ifndef _ROBOT_
#define _ROBOT_

#include "Robot.h"

// there is -1 default type with 
Robot::Robot(int type = -1) : type(type), strength(1), HP(1), name("unnamed"), moved(false) {
    /*Intentionally empty*/
}

Robot::Robot(int newType, int newStrength, int newHit, string name) :
    type(newType), strength(newStrength), HP(newHit), name(name), moved(false){
    
    /*Intentionally empty*/
}

Robot::~Robot(){
    /*Intentionally empty*/
}

int Robot::getTypeAsInt() const{
    return type;
}

//the getType implementations of robot that is not used in main or world
string Robot::getType() const{

    switch (type){
    case 0: 
        return "optimusprime";
    case 1:
        return "robocop";
    case 2:
        return "roomba";
    case 3:
        return "bulldozer";
    case 4:
        return "kamikaze";
    }

    return "unknown";
}

int Robot::getDamage() const{
    int damage;
    // All robots inflict damage
    damage = (rand() % strength) + 1;
    //if the robot is a kamikaze robot, the damage is the hitpoints of the kamikaze.
    /*cout << getType() << " attacks for " <<
    damage << " points!" << endl;*/
    //calculate additional damage here depending on the type
    return damage;
}

//accesors (getters)
int Robot::getStrength() const{
    return strength;
}

int Robot::getHP() const{
    return HP;
}

string Robot::getName() const{
    return name;
}

bool Robot::hasMoved() const{
    return moved;
}

//mutators (setters)
void Robot::setType(int newType){
    this->type = newType;
}

void Robot::setStrength(int newStrength){
    this->strength = newStrength;
}

void Robot::setHP(int newHit){
    this->HP = newHit;
}

void Robot::setMoved(bool newMoved){
    this->moved = newMoved;
}

//the fight of robots
int Robot::fight(Robot* S){

    //if the type is kamikaze, just do one attack
    if(type == 4){
        int d_r = getDamage();
        //hitmessage
        cout << name << "(" << HP << ") hits " << S->getName() << "(" << S->getHP() << ") with " << d_r << endl;
        HP -= d_r;
        S->setHP(S->getHP() - d_r);

        //dead announce
        cout << name << " is dead!" << endl;
        //hit message
        cout << "The new hitpoins of " << S->getName() << " is " << S->getHP() << endl; 
        
        //and return condition
        if(S->getHP() <= 0){
            cout << S->getName() << " is dead!" << endl;
            return 2;
        }
        else
            return 0;
    }
    
    //continue until a robot dies
    while (HP > 0 && S->getHP() > 0) {
        // Attacker's turn
        int d_r = getDamage();
        //hitmessage
        cout << name << "(" << HP << ") hits " << S->getName() << "(" << S->getHP() << ") with " << d_r << endl;

        S->setHP(S->getHP() - d_r);
        cout << "The new hitpoins of " << S->getName() << " is " << S->getHP() << endl; 
        // Victim is dead
        if (S->getHP() <= 0) {
            cout << S->getName() << " is dead!" << endl;
            return 1;
        }



        // Victim's turn
        int d_s = S->getDamage();
        //hitmessage
        cout << S->getName() << "(" << S->getHP() << ") hits " << name << "(" << HP << ") with " << d_s << endl;
        HP -= d_s;

        cout << "The new hitpoins of " << name << " is " << HP << endl; 
        //kamikaze victims situation
        if(S->getType() == "kamikaze"){
            S->setHP(S->getHP() - d_s);
            cout << S->getName() << " is dead!" << endl;
            if (HP <= 0){
                cout << name << " is dead!" << endl;
                return 2;
            }
            else
                return 1;
        }


        // Attacker is dead
        if (HP <= 0) {
            cout << name << " is dead!" << endl;
            return 0; 
        }
    }

    return true;
}


#endif