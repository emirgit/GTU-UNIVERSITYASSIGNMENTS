#ifndef _HUMANIC_H_
#define _HUMANIC_H_

#include "Robot.h"

//Humanic class inherited from Robot
class Humanic : public Robot{
    public:
        //constructors
        Humanic(int type);
        Humanic(int newType, int newStrength, int newHit, string name);

        //overrided getDamage and getType function
        int getDamage() const override;
        string getType() const override;
};

#endif