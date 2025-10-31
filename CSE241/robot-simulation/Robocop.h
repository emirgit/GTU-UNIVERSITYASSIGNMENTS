#ifndef _ROBOCOP_H_
#define _ROBOCOP_H_

#include "Humanic.h"

//Robocop class inherited from Humanic
class Robocop : public Humanic{
  public:
    //constructors
    Robocop();
    Robocop(int newStrength, int newHit, string name);

    //overrided getDamage and getType function
    int getDamage() const override;
    string getType() const override;
};

#endif