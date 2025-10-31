#ifndef _FIELDS_
#define _FIELDS_

#include "Fields.h"

Field::~Field(){

}

// Getter for name
string FieldFormat::getName() const {
    return name;
}

// Setter for name
void FieldFormat::setName(const string& newName) {
    name = newName;
}

// Getter for type
string FieldFormat::getType() const {
    return type;
}

// Setter for type
void FieldFormat::setType(const string& newType) {
    type = newType;
}

// Getter for isSingle
bool FieldFormat::getIsSingle() const {
    return isSingle;
}

// Setter for isSingle
void FieldFormat::setIsSingle(bool newIsSingle) {
    isSingle = newIsSingle;
}


//Constructors that takes string as parameter
//and parse them and convert to needed data type
FieldInt::FieldInt(string input){
    data = stoi(input);
}

FieldIntVector::FieldIntVector(string input){
    Parse parserbySemi(':');
    parserbySemi.parseLine(input);
    parserbySemi.setIterBegin();

    while(!parserbySemi.iterInEnd()){
        data.push_back(stoi(parserbySemi.getElement()));
    }

}

//Constructors that takes string as parameter
//and parse them and convert to needed data type
FieldDouble::FieldDouble(string input){
    data = stod(input);
}

FieldDoubleVector::FieldDoubleVector(string input){
    Parse parserbySemi(':');
    parserbySemi.parseLine(input);
    parserbySemi.setIterBegin();

    while(!parserbySemi.iterInEnd()){
        data.push_back(stod(parserbySemi.getElement()));
    }
}

//Constructors that takes string as parameter
FieldStr::FieldStr(string input){
    data = input;
}

FieldStrVector::FieldStrVector(string input){
    Parse parserbySemi(':');
    parserbySemi.parseLine(input);
    parserbySemi.setIterBegin();

    while(!parserbySemi.iterInEnd()){
        data.push_back(parserbySemi.getElement());
    }
}

//operator to apply sorting
//if it is multi just compare first entry
bool FieldInt::operator <(const Field& other) const {
    const FieldInt& otherField = dynamic_cast<const FieldInt&>(other);
    return data < otherField.data;
}

bool FieldDouble::operator <(const Field& other) const {
    const FieldDouble& otherField = dynamic_cast<const FieldDouble&>(other);
    return data < otherField.data;
}

bool FieldIntVector::operator <(const Field& other) const {
    const FieldIntVector& otherField = dynamic_cast<const FieldIntVector&>(other);
    return data[0] < otherField.data[0];
}

bool FieldDoubleVector::operator <(const Field& other) const {
    const FieldDoubleVector& otherField = dynamic_cast<const FieldDoubleVector&>(other);
    return data[0] < otherField.data[0];
}

bool FieldStr::operator <(const Field& other) const {
    const FieldStr& otherField = dynamic_cast<const FieldStr&>(other);
    return data < otherField.data;
}

bool FieldStrVector::operator <(const Field& other) const {
    const FieldStrVector& otherField = dynamic_cast<const FieldStrVector&>(other);
    return data[0] < otherField.data[0];
}

//getter functions to return datas
int FieldInt::getData() const {
    return data;
}

const vector<int>& FieldIntVector::getData() const {
    return data;
}

double FieldDouble::getData() const {
    return data;
}

const vector<double>& FieldDoubleVector::getData() const {
    return data;
}

string FieldStr::getData() const {
    return data;
}

const vector<string>& FieldStrVector::getData() const {
    return data;
}

//isMatched function to search the given value
bool FieldInt::isMatched(const string& value) const {
    return data == stoi(value);
}

//finding data from beginin to end if data is not end it is not found
bool FieldIntVector::isMatched(const string& value) const {
    int intValue = stoi(value);
    return find(data.begin(), data.end(), intValue) != data.end();
}

bool FieldDouble::isMatched(const string& value) const {
    return data == stod(value);
}

bool FieldDoubleVector::isMatched(const string& value) const {
    double doubleValue = stod(value);
    return find(data.begin(), data.end(), doubleValue) != data.end();
}

//try to find tha value and if it is not string::npos it is found
bool FieldStr::isMatched(const string& value) const {
    return data.find(value) != string::npos;
}

bool FieldStrVector::isMatched(const string& value) const {
    for (const auto& str : data) {
        if (str.find(value) != string::npos) {
            return true;
        }
    }
    return false;
}

//writes datas to given output stream
void FieldInt::writeDataToFile(ofstream& fwrite) const {
    fwrite << data;
}

void FieldIntVector::writeDataToFile(ofstream& fwrite) const {
    for (int j = 0; j < data.size(); j++) {
        fwrite << data[j];
        if (j != data.size() - 1)
            fwrite << ':';
    }
}

void FieldDouble::writeDataToFile(ofstream& fwrite) const {
    fwrite << data;
}

void FieldDoubleVector::writeDataToFile(ofstream& fwrite) const {
    for (int j = 0; j < data.size(); j++) {
        fwrite << data[j];
        if (j != data.size() - 1)
            fwrite << ':';
    }
}

void FieldStr::writeDataToFile(ofstream& fwrite) const {
    fwrite << data;
}

void FieldStrVector::writeDataToFile(ofstream& fwrite) const {
    for (int j = 0; j < data.size(); j++) {
        fwrite << data[j];
        if (j != data.size() - 1)
            fwrite << ':';
    }
}


#endif