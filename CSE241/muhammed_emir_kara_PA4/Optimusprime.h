#ifndef _OPTIMUSPRIME_H_
#define _OPTIMUSPRIME_H_

#include "Humanic.h"

//optimus prime class inherited from Humanic
class Optimusprime : public Humanic{
        public:
        //constructors
        Optimusprime();
        Optimusprime(int newStrength, int newHit, string name);

        //overrided getDamage and getType function
        int getDamage() const override;
        string getType() const override;
};

#endif