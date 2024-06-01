#ifndef _PARSE_H_
#define _PARSE_H_

#include <iostream>
#include <vector>
#include <sstream>
#include "Errors.h"

using namespace std;

//Parse class to parse array
class Parse {
private:
    //delimiter to delim the string
    char del;
    //store the delimited strings
    vector<string> v;
    //using iter to access the element of vector
    vector<string>::iterator iter;

public:
    //default and one parameter constructor
    Parse(char del = ' ');

    // Line parser
    void parseLine(const string& line);
    void parseLineImmune(const string& line);

    //setIterBegin() function to set Iter to begin()
    void setIterBegin();
    //check whether the iter at the end of the vector
    bool iterInEnd() const; 
    //get the element at current
    string& getElement();
    //get vector address of object
    vector<string> getVector();
    //get vector size;
    int getVectorSize();
    //print vector
    //void printVector();
};

#endif