#ifndef _ROOMBA_H_
#define _ROOMBA_H_

//including robot
#include "Robot.h"

//the Roomba class inherited from Robot
class Roomba : public Robot{
    public:
        //constructors
        Roomba();
        Roomba(int newStrength, int newHit, string name);

        //overrided getDamage and getType function
        int getDamage() const override;
        string getType() const override;
};

#endif