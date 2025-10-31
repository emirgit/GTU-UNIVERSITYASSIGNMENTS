#ifndef _ROBOT_H_
#define _ROBOT_H_

#include<iostream>
#include<string.h>
using namespace std;

class Robot{
    public:
        //default and type constructor
        Robot(int type);
        Robot(int newType, int newStrength, int newHit, string name);
        virtual ~Robot(); // virtual destructor to prevent memory leak
        // Initialize robot to new type, strength, hit points
        // for type, strength, and hit points
        virtual int getDamage() const;
        // Returns amount of damage this robot
        // inflicts in one round of combat
    
        //a helper function which returns the robot type
        int getTypeAsInt() const;
        virtual string getType() const;
        string getName() const;
        int getStrength() const;
        int getHP() const;
        bool hasMoved() const;
        // Also add appropriate accessor and mutator functions
        void setMoved(bool newMoved);
        void setType(int newType);
        void setStrength(int newStrength);
        void setHP(int newHit);

        int fight(Robot* S);

    //I just do type as protected for good implementations
    //Otherwise, it could be public but it is better
    protected:
        //a member data which defines the type
        int type;
    private:
        //a member data which stores whether robot moved
        bool moved;
        // a member data which stores the name
        string name;
        //a member data which stores the strength
        int strength; 
        //a member data which stores the hitpoints
        int HP;
};





#endif