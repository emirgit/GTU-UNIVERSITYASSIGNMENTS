#ifndef _BULLDOZER_H_
#define _BULLDOZER_H_

#include "Robot.h"

// Bulldozer class inherited from Robot
class Bulldozer : public Robot{
    public:
        //constructors
        Bulldozer();
        Bulldozer(int newStrength, int newHit, string name);

        //overrided getDamage and getType function
        int getDamage() const override;
        string getType() const override;
};

#endif