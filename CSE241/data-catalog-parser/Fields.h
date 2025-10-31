#ifndef _FIELDS_H_
#define _FIELDS_H_

#include<string>
#include<vector>
#include<algorithm>
#include <fstream>
#include "Parse.h"

using namespace std;

class FieldFormat {
private:
    string name;
    string type;
    bool isSingle;

public:
    // Getter for name
    string getName() const;

    // Setter for name
    void setName(const string& newName);

    // Getter for type
    string getType() const;

    // Setter for type
    void setType(const string& newType);

    // Getter for isSingle
    bool getIsSingle() const;

    // Setter for isSingle
    void setIsSingle(bool newIsSingle);
};

//pure virtual class
class Field {
public:
    virtual ~Field();
    virtual bool operator <(const Field& other) const = 0;
    virtual bool isMatched(const string& value) const = 0;
    virtual void writeDataToFile(ofstream& fwrite) const = 0;
};

/*
The inherited Field
single:
int
double
string
multi:
int
double
string

is classic getter function
getData()

operator< for stroign algoritmh

isMatched for seraching algorithm

and writeDataToFile to write datas to file

and constructors

*/
class FieldInt : public Field {
public:
    FieldInt(string input);
    int getData() const;
    bool operator<(const Field& other) const override;
    bool isMatched(const string& value) const override;
    void writeDataToFile(ofstream& fwrite) const override;
private:
    int data;
};

class FieldIntVector : public Field {
public:
    FieldIntVector(string input);
    const vector<int>& getData() const;
    bool operator<(const Field& other) const override;
    bool isMatched(const string& value) const override;
    void writeDataToFile(ofstream& fwrite) const override;
private:
    vector<int> data;
};

class FieldDouble : public Field {
public:
    FieldDouble(string input);
    double getData() const;
    bool operator<(const Field& other) const override;
    bool isMatched(const string& value) const override;
    void writeDataToFile(ofstream& fwrite) const override;
private:
    double data;
};

class FieldDoubleVector : public Field {
public:
    FieldDoubleVector(string input);
    const vector<double>& getData() const;
    bool operator<(const Field& other) const override;
    bool isMatched(const string& value) const override;
    void writeDataToFile(ofstream& fwrite) const override;
private:
    vector<double> data;
};

class FieldStr : public Field {
public:
    FieldStr(string input);
    string getData() const;
    bool operator<(const Field& other) const override;
    bool isMatched(const string& value) const override;
    void writeDataToFile(ofstream& fwrite) const override;
private:
    string data;
};

class FieldStrVector : public Field {
public:
    FieldStrVector(string input);
    const vector<string>& getData() const;
    bool operator<(const Field& other) const override;
    bool isMatched(const string& value) const override;
    void writeDataToFile(ofstream& fwrite) const override;
private:
    vector<string> data;
};

#endif