#ifndef _WORLD_H_
#define _WORLD_H_


#include<iostream>
using namespace std;
#include<cstdlib>
#include<ctime>
#include<string>
//this 2 class doesn't have to be included because,
//they will be included in derived class
//But in case of changing in subclasses, they are included
#include "Robot.h"
#include "Humanic.h"

#include "Optimusprime.h"
#include "Robocop.h"
#include "Kamikaze.h"
#include "Bulldozer.h"
#include "Roomba.h"

//initial condition of robots
//There is no initial condition for humanics because it is a base class of some type of robots
#define BULLDOZER_STRENGTH 50
#define BULLDOZER_HP 200
#define KAMIKAZE_STRENGTH 10
#define KAMIKAZE_HP 10
#define OPTIMUSPRIME_STRENGTH 100
#define OPTIMUSPRIME_HP 100
#define ROBOCOP_STRENGTH 30
#define ROBOCOP_HP 40
#define ROOMBA_STRENGTH 3
#define ROOMBA_HP 10

//gridsize
#define GRID_SIZE 10
// initial count of each robot type:
#define NUMBER_OF_EACH_ROBOT 5
#define NUMBER_OF_TYPE 5

class World {
private:
    //grid
    Robot* grid[GRID_SIZE][GRID_SIZE];
    //number of robot
    int numberOfRobot;

    int winners[NUMBER_OF_TYPE];
    //resteding move flag function
    void resetMoved();
    //move of robot
    void move(int x, int y);
    // deleting by downcasting
    void delbyType(Robot* robot);
    //checl the result of the fight
    void checkFight(int condition, int x, int y, int tempX, int tempY);

public:
    void simulateSoMuch();
    //constructor and destructor
    World();
    ~World();
    //palce robots initially
    void placeRobots();
    //simulation of the game
    void simulate();
    void displayWorld();
};

#endif