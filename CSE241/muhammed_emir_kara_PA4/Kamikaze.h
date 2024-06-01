#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include "Robot.h"

//Kamikaze class inherited from Robot
class Kamikaze : public Robot{
    public:
        //constructors
        Kamikaze();
        Kamikaze(int newStrength, int newHit, string name);

        //overrided getDamage and getType function
        int getDamage() const override;
        string getType() const override;
};

#endif