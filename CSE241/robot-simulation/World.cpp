#ifndef _WORLD_
#define _WORLD_

#include "World.h"


//World default constructor set the grid and the other member data and also seed to random number generator
World::World() : numberOfRobot(0){
    //Seed the random number generator
    srand(time(nullptr));

    //Initialize the grid with nullptr
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = nullptr;
        }
    }

    for(int i = 0; i < NUMBER_OF_TYPE; i++){
        winners[i] = 0;
    }
}

World::~World(){
    //Deallocate memory for robots
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr)
                delbyType(grid[i][j]);
        }
    }
}

//place Robots funtcions place all robots by the rules that is given by pdf. It can be also changed
void World::placeRobots(){
    //how many types of robots are there in world
    for(int type = 0; type < NUMBER_OF_TYPE; type++) {
        // how many robots will be placed for each type
        for(int seqNum = 0; seqNum < NUMBER_OF_EACH_ROBOT; seqNum++) {
            // x and y is random cordinates in grid
            int x, y;
            string name;
            do {
                x = rand() % GRID_SIZE; 
                y = rand() % GRID_SIZE;
            } while(grid[x][y] != nullptr);

            // place the robot by the type 
            switch (type) {
                // case 0 for optimus prime
                case 0: 
                    name = "optimusprime_" + to_string(seqNum);
                    grid[x][y] = new Optimusprime(OPTIMUSPRIME_STRENGTH, OPTIMUSPRIME_HP, name);
                    break;
                // case 1 for robocop
                case 1:
                    name = "robocop_" + to_string(seqNum); 
                    grid[x][y] = new Robocop(ROBOCOP_STRENGTH, ROBOCOP_HP, name);
                    break;
                // case 2 for roomba
                case 2:
                    name = "roomba_" + to_string(seqNum);
                    grid[x][y] = new Roomba(ROOMBA_STRENGTH, ROOMBA_HP, name);
                    break;
                // case 3 for bulldozer
                case 3:
                    name = "bulldozer_" + to_string(seqNum);
                    grid[x][y] = new Bulldozer(BULLDOZER_STRENGTH, BULLDOZER_HP, name);
                    break;
                //case 4 for kamikaze
                case 4:
                    name = "kamikaze_" + to_string(seqNum);
                    grid[x][y] = new Kamikaze(KAMIKAZE_STRENGTH, KAMIKAZE_HP, name);
                    break;
            }
            //increase the number of robot for each placed robot
            numberOfRobot++;
        }
    }
}

//in each round in simulation reset flag of robot to false 
void World::resetMoved(){
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->setMoved(false);
            }
        }
    }
}


// remove the robot from grid by downcasting 
//this will perevent the memory leak
void World::delbyType(Robot* robot){
    string type = robot->getType();

    if (type == "optimusprime"){
        Optimusprime* optimusprimeRobot = dynamic_cast<Optimusprime*>(robot);
        delete optimusprimeRobot;
    } 
    else if (type == "robocop"){
        Robocop* robocopRobot = dynamic_cast<Robocop*>(robot);
        delete robocopRobot;
    }
    else if (type == "roomba"){
        Roomba* roombaRobot = dynamic_cast<Roomba*>(robot);
        delete roombaRobot;
    } 
    else if (type == "bulldozer"){
        Bulldozer* bulldozerRobot = dynamic_cast<Bulldozer*>(robot);
        delete bulldozerRobot;
    } 
    else{
        Kamikaze* kamikazeRobot = dynamic_cast<Kamikaze*>(robot);
        delete kamikazeRobot;
    }

    //decrease the number of robot
    numberOfRobot--;
}

//this will check the result of fight of robots
void World::checkFight(int condition, int x, int y, int tempX, int tempY){
    grid[x][y]->setMoved(true);

    if (condition == 1){
        delbyType(grid[tempX][tempY]);
        grid[tempX][tempY] = grid[x][y];
    }
    else if (condition == 0){
        delbyType(grid[x][y]);
    }
    // else for the condition 2 
    else{
        delbyType(grid[x][y]);
        delbyType(grid[tempX][tempY]);
        grid[tempX][tempY] = nullptr;
    }
    grid[x][y] = nullptr;

}

//move function 
void World::move(int x, int y) {
    // 0: up, 1: down, 2: left, 3: right
    int direction, tempX, tempY;
    //set all element with false 
    //it is feature of cpp if we type just a 0 or false in a matrix
    //it will change all cell to false
    bool visited[GRID_SIZE][GRID_SIZE] = {false};
    //make the cell of the robot visited to prevent him to fight with itself
    visited[x][y] = true;

    // x and y current robots coordinates tempX and tempY will be the coordinates of the robot found
    tempX = x;
    tempY = y;
    //continue until robot find an robot

    while (!grid[x][y]->hasMoved()) {

        // check if the robot has a cell it didn't visit
        bool allVisited = true;
        if((tempX >0 && !visited[tempX - 1][tempY]) || (tempX < GRID_SIZE - 1 && !visited[tempX + 1][tempY]) ||
            (tempY > 0 && !visited[tempX][tempY - 1]) ||(tempY < GRID_SIZE - 1 && !visited[tempX][tempY + 1]) ){
                allVisited = false;

            }

        // If all adjacent cells are visited, reset the visited flag
        if (allVisited) {
            for (int i = 0; i < GRID_SIZE; ++i) {
                for (int j = 0; j < GRID_SIZE; ++j) {
                    visited[i][j] = false;
                }
            }
            // do not fight with itself
            visited[x][y] = true;
            // do not come same place (to prevent while loop)
            visited[tempX][tempY] = true;
        }

        // Randomly select a direction until a valid direction is found
        do {
            
            direction = rand() % 4;
        } while ((direction == 0 && (tempX == 0 || visited[tempX - 1][tempY])) ||
                 (direction == 1 && (tempX == GRID_SIZE - 1 || visited[tempX + 1][tempY])) ||
                 (direction == 2 && (tempY == 0 || visited[tempX][tempY - 1])) ||
                 (direction == 3 && (tempY == GRID_SIZE - 1 || visited[tempX][tempY + 1])));


        switch (direction) {
            case 0: // up
                //cout << grid[x][y]->getName() << "'s trying to go up !" << endl;
                tempX--;
                while (tempX >= 0 && !visited[tempX][tempY]) {
                    if (grid[tempX][tempY] != nullptr) {
                        checkFight(grid[x][y]->fight(grid[tempX][tempY]), x, y, tempX, tempY);
                        return;
                    }

                    visited[tempX][tempY] = true;
                    tempX--;
                }
                //tempX is now -1 make it 0 because we substract 1 when searching next grid
                tempX++;

                break;
            case 1: // down
                //cout << grid[x][y]->getName() << "'s trying to go down !" << endl;
                tempX++;
                while (tempX < GRID_SIZE && !visited[tempX][tempY]) {
                    if (grid[tempX][tempY] != nullptr) {
                        checkFight(grid[x][y]->fight(grid[tempX][tempY]), x, y, tempX, tempY);
                        return;
                    }

                    visited[tempX][tempY] = true;
                    tempX++;
                }
                //tempX is now GRID_SIZE make it GRID_SIZE - 1 because we added 1 when searching next grid
                tempX--;

                break;
            case 2: // left
                //cout << grid[x][y]->getName() << "'s trying to go left !" << endl;
                tempY--;
                while (tempY >= 0 && !visited[tempX][tempY]) {
                    if (grid[tempX][tempY] != nullptr) {
                        checkFight(grid[x][y]->fight(grid[tempX][tempY]), x, y, tempX, tempY);
                        return;
                    }

                    visited[tempX][tempY] = true;
                    tempY--;
                }
                //tempY is now -1 make it 0 because we substract 1 when searching next grid
                tempY++;

                break;
            case 3: // right
                //cout << grid[x][y]->getName() << "'s trying to go right !" << endl;
                tempY++;
                while (tempY < GRID_SIZE && !visited[tempX][tempY]) {
                    if (grid[tempX][tempY] != nullptr) {
                        checkFight(grid[x][y]->fight(grid[tempX][tempY]), x, y, tempX, tempY);
                        return;
                    }

                    visited[tempX][tempY] = true;
                    tempY++;
                }
                //tempY is now GRID_SIZE make it GRID_SIZE - 1 because we added 1 when searching next grid
                tempY--;

                break;
        }

    }

}

//the simulat efunctions simulate the world step by step and round by round
void World::simulate() {

    while (numberOfRobot > 1){
        //one round 
        resetMoved();

        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                // one step
                if (grid[i][j] != nullptr && !grid[i][j]->hasMoved() && numberOfRobot > 1) {
                    //if the robot hasn't moved yet move it
                    move(i, j);
                    cout << endl;
                    /*
                    displayWorld();
                    cout << endl << endl;
                    string s;
                    getline(cin, s);
                    */
                }   
            }
        }

    }

    //war end 
    cout << "WAR ENDED UP!!" << endl;

    //find robot has won
    if(numberOfRobot == 1){
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (grid[i][j] != nullptr) {
                    cout << "The winner is: " << grid[i][j]->getName() << endl;
                    winners[grid[i][j]->getTypeAsInt()]++;
                    return;
                }
            }
        }
    }
    //if the kamikaze kill the other robot. it will die also
    else{
        cout << "There is no winner. Kamikaze just did his job successfully" << endl;
    }
}


//for debugging
void World::displayWorld(){
    
    for(int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            if(grid[i][j] == nullptr)
                cout << " |";
            else{
                switch (grid[i][j]->getTypeAsInt()){
                
                case 0: 
                    cout << "O|";
                    break;
                case 1:
                    cout << "C|";
                    break;
                case 2:
                    cout << "R|";
                    break;
                case 3:
                    cout << "B|";
                    break;
                case 4:
                    cout << "K|";
                    break;
                default:
                    cout << "N|";
                }
            }

        }
        cout << endl;
        for (int j = 0; j < GRID_SIZE; j++){
            cout << "--";
        }
        cout << endl;
    }


}


void World::simulateSoMuch(){
    /*int times = 10000;

    for(int i = 0; i < times; i++){
        placeRobots();
        simulate();
    }

    int counter = 0;
    for(int i = 0; i < NUMBER_OF_TYPE; i++){
        counter += winners[i];
        cout << "type " << i << " won " << winners[i] << " time!" << endl;         
    }

    cout << "no win situation is " << times - counter << endl;*/

    placeRobots();
    displayWorld();
    cout << numberOfRobot;
    simulate();
}
#endif