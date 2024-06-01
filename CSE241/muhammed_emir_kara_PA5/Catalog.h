#ifndef _CATALOG_H_
#define _CATALOG_H_

#include <fstream>
#include <algorithm>
#include "Parse.h"
#include "Errors.h"
#include "Fields.h"



class Catalog{

private:
    //fields stores the information about datas
    vector<FieldFormat> fields;
    //datas stores the datas given by file
    vector<vector<Field*>> datas;

    //readOtherLines reads the lines except first line that is field information
    void readOtherLines(ifstream& f, ofstream& fwrite);
    
    //checkComands function check whether the commands is correct or not
    bool checkCommands(Parse& parser, string& value, int& fieldIndex);
    //isField check if string isField or not
    int isField(const string& str);
    
    //convert functons convert string of array to double or int
    vector<int> convertToInt(const vector<string>& strings);
    vector<double> convertToDouble(const vector<string>& strings);

    //IsDuplicate cheks whether given string is avaiable in datas
    bool IsDuplicate(string str, int index);
    bool IsDuplicate(vector<string> str, int index);
    //checkException take the parser and check whether the lines includes duplicate or missing field
    void checkExceptions(Parse& parser);
    //checkErrors for file stream
    int check_errors(ifstream* f) const;
    //writeFieldsToFile writes field to file
    void writeFieldsToFile(ofstream& fwrite);
    //compareByColumn is comparator function for sorting
    bool compareByColumn(const vector<Field*>& vec1, const vector<Field*>& vec2, int field);
    //writeDataToFile writes a data to file
    void writeDataToFile(ofstream& fwrite, const vector<Field*>& data);
    //writeDatasToFile writes the datas to file
    void writeDatasToFile(ofstream& fwrite);
    //searchValue functions search the given value in datas
    void searchValue(const string& value, const int& fieldIndex, ofstream& fwrite);

public:
    //constructor
    Catalog();
    //readDataFile function reads the data from file and store them to datas
    void readDataFile(const string& readFileName, const string& writeFileName);
    //readCommands function read the commands txt 
    void readCommands(const string& readFileName, const string& writeFileName);
    //the Fields is allocated dynmically so it deletes the data to prevent memory leak
    void deleteDatas();
};

#endif