#ifndef _CATALOG_
#define _CATALOG_

#include "Catalog.h"

Catalog::Catalog(){
// intentionally empty
}   

//readDataFile function reads the data from file and store them to datas
void Catalog::readDataFile(const string& readFileName, const string& writeFileName) {
    //input stream and output stream to get and write the datas
    ifstream f(readFileName);
    ofstream fwrite(writeFileName);
    
    //if file cannot open throw fileopen error
    if (!f.is_open())
        throw FileOpenError();

    //line to read the file and parser to parse and store the datas
    string line;
    Parse parser('|');

    //reading the first line
    getline(f, line);

    //parse the line
    parser.parseLine(line);
    parser.setIterBegin();

    while(!parser.iterInEnd()){
        //field and parserbySemi to parse the multi data
        FieldFormat field;
        Parse parserbySemi(':');


        parserbySemi.parseLine(parser.getElement());
        parserbySemi.setIterBegin();

        //parse and store name type and single or not
        if(!parserbySemi.iterInEnd())
            field.setName(parserbySemi.getElement());

        if(!parserbySemi.iterInEnd())
            field.setType(parserbySemi.getElement());


        if(!parserbySemi.iterInEnd()){
            string checkIsArray = parserbySemi.getElement();
            if(checkIsArray == "multi"){
                field.setIsSingle(0);
            }
            else if(checkIsArray == "single"){
                field.setIsSingle(1);
            }
            else
                cerr << " ERR different thing from isSingle " << endl;
            
        }
        //put the data
        fields.push_back(field);
    }

    //write Fields to file
    writeFieldsToFile(fwrite);
    //reading the other lines
    readOtherLines(f, fwrite);

    //closing input and output file
    f.close();
    fwrite.close();
}


void Catalog::readOtherLines(ifstream& f, ofstream& fwrite){
    //uniqueCtr count the unique element from given file
    int uniqueCtr = 0;
    string line;

    while(getline(f, line)){
        //if the datas cannot read from file, stop the processing
        if (check_errors(&f)) {
            //skip the data processing and break
            break;
        }

        //parse the lines
        Parse parser('|');
        parser.parseLine(line);
        //set iter to begin
        parser.setIterBegin();
        
        try{
            
            //check the lines whether have duplicate or missing filed
            checkExceptions(parser);
            
            
            parser.setIterBegin();

            int counter = 0;
            //parse Field put it to data
            vector<Field *> data;
            while(!parser.iterInEnd()){
                FieldFormat& field = fields[counter];
                
                //take the information of field and push them by information
                if(field.getIsSingle()){
                    
                    if(field.getType() == "integer"){
                        data.push_back(new FieldInt(parser.getElement()));
                    }
                    else if(field.getType() == "double"){
                        data.push_back(new FieldDouble(parser.getElement()));
                    }
                    else{
                        data.push_back(new FieldStr(parser.getElement()));
                    }
                    
                }
                else{
                    
                    if(field.getType() == "integer"){
                        data.push_back(new FieldIntVector(parser.getElement()));
                    }
                    else if(field.getType() == "double"){
                        data.push_back(new FieldDoubleVector(parser.getElement()));
                    }
                    else{
                        data.push_back(new FieldStrVector(parser.getElement()));
                    }
                    

                }

                counter++;
            }
            //if there is no duplicate or missing push it and increase the unique counter
            datas.push_back(data);
            uniqueCtr++;       
        }
        //if there is error write the given error to file
        catch(MissingFieldException& e) {
            fwrite << e.what() << endl << line << endl;
        }
        catch(DuplicateEntryException& e) {
            fwrite << e.what() << endl << line << endl;
        }
        catch (const std::exception& e) {
            cerr << "Unknown Error" ;
        }
        
    }

    fwrite << uniqueCtr << " unique entries" << endl; 
}


//check_errors from previous homeworks
int Catalog::check_errors(ifstream* f) const{
    int stop = 0;

    if (f->eof()) {
        stop = 0;
    }
    if (f->fail()) {
        stop = 1;
    }
    if (f->bad()) {
        stop = 1;
    }

    return stop;
}

void Catalog::checkExceptions(Parse& parser){
    //checking if the first line is same or not
    parser.setIterBegin();

    //if size of vector is not same with field, that's mean there is missing field
    if(parser.getVectorSize() != fields.size())
        throw MissingFieldException();

    //if the line is empty or blank return missing field error
    while(!parser.iterInEnd()){
        string curElement = parser.getElement();

        if(curElement.empty() || curElement.find_first_not_of(' ')){
            throw MissingFieldException();
        }
    }


    parser.setIterBegin();
    //traverse throughout fields and check the element is duplicated ornot
    if(fields[0].getIsSingle()){
        if(IsDuplicate(parser.getElement(), 0))
            throw DuplicateEntryException();
    }
    else{
        //this is for multi and check it by parsebysemi and compare the vectors
        Parse parsebySemi(':');
        parsebySemi.parseLine(parser.getElement());
        vector<string> vec = parsebySemi.getVector();
        if(IsDuplicate(vec, 0)){
            throw DuplicateEntryException();
        }
    }
    
    //checking the all lines has field


}

//convert functions

/*
template<typename T>
vector<T> Catalog::convertToT(const vector<string>& strings){
    vector<T> datas;
    for(const string&str : strings){
        ...
    }

    return datas;
}

*/

//convert function to convert given vector of string to  data types
vector<int> Catalog::convertToInt(const vector<string>& strings) {
    vector<int> integers;
    for (const string& str : strings) {
        integers.push_back(stoi(str));
    }
    return integers;
}

vector<double> Catalog::convertToDouble(const vector<string>& strings) {
    vector<double> doubles;
    for (const string& str : strings) {
        doubles.push_back(stod(str));
    }
    return doubles;
}


//checking there is duplicated datas
bool Catalog::IsDuplicate(string str, int index){
    FieldFormat& field = fields[index];

    for (const auto& data : datas) {
        if(field.getType() == "integer"){
            //dynamic casting and check the datas
            FieldInt* fieldIntPtr = dynamic_cast<FieldInt*>(data[index]);
            if(stoi(str) == fieldIntPtr->getData())
                return 1;
        }
        else if(field.getType() == "double"){
            //dynamic casting and check the datas
            FieldDouble* fieldDobulePtr = dynamic_cast<FieldDouble*>(data[index]);
            if (stod(str) == fieldDobulePtr->getData())
                return 1;
        }
        else{
            //dynamic casting and check the datas
            FieldStr* fieldStrPtr = dynamic_cast<FieldStr*>(data[index]);
            if(str == fieldStrPtr->getData())
                return 1;
        }
    }

    return 0;
}


//checking there is duplicated datas
bool Catalog::IsDuplicate(vector<string> str, int index){
    FieldFormat& field = fields[index];

    for (const auto& data : datas) {
        if(field.getType() == "integer"){
            //dynamic casting and check the datas
            FieldIntVector* fieldIntVectorPtr = dynamic_cast<FieldIntVector*>(data[index]);
            if(convertToInt(str) == fieldIntVectorPtr->getData())
                return 1;
        }
        else if(field.getType() == "double"){
            //dynamic casting and check the datas
            FieldDoubleVector* fieldDobuleVectorPtr = dynamic_cast<FieldDoubleVector*>(data[index]);
            if(convertToDouble(str) == fieldDobuleVectorPtr->getData())
                return 1;
        }
        else{
            //dynamic casting and check the datas
            FieldStrVector* fieldStrVectorPtr = dynamic_cast<FieldStrVector*>(data[index]);
            if(str == fieldStrVectorPtr->getData())
                return 1;
        }
    }

    return 0;
}

//writing field to file
void Catalog::writeFieldsToFile(ofstream& fwrite){
    for(int i = 0; i < fields.size(); i++){
        fwrite << fields[i].getName();
        //not put '|' to end of line 
        if(i != fields.size() - 1)
            fwrite << "|";
    }
    fwrite << endl;
}

//write data to file
void Catalog::writeDataToFile(ofstream& fwrite, const vector<Field*>& data) {
    for (int i = 0; i < data.size(); i++) {
        //invoke the virtual function
        data[i]->writeDataToFile(fwrite);

        // Add '|' between fields, but not after the last one
        if (i != data.size() - 1)
            fwrite << '|';
    }
    fwrite << endl;
}

//writeDatasToFile writes the datas to file
void Catalog::writeDatasToFile(ofstream& fwrite) {
    for (int i = 0; i < datas.size(); i++) {
        writeDataToFile(fwrite, datas[i]);
    }
}

//compareByColumn is comparator function for sorting
bool compareByField(const vector<Field*>& vec1, const vector<Field*>& vec2, int field){
    return *(vec1[field]) < *(vec2[field]);
}

// class CompareByField {
// public:
//     CompareByField(int field) : field(field) {}

//     bool operator()(const std::vector<Field*>& vec1, const std::vector<Field*>& vec2) const {
//         return *(vec1[field]) < *(vec2[field]);
//     }

// private:
//     int field;
// };

//searchValue functions search the given value in datas
void Catalog::searchValue(const string& value, const int& fieldIndex, ofstream& fwrite) {
    for (const auto& dataRow : datas) {

        Field* field = dataRow[fieldIndex];
        //invoke virtual function
        if (field->isMatched(value)) {
            writeDataToFile(fwrite, dataRow);
        }
    }
}


void Catalog::readCommands(const string& readFileName, const string& writeFileName) {
    //open commands txt
    ifstream f(readFileName);
    //open output txt with append mode
    ofstream fwrite(writeFileName, ios::app);
    string line;

    //get all line
    while(getline(f, line)){
        //check error function from others homework
        if (check_errors(&f)) {
            //skip the data processing and break
            break;
        }

        Parse parser;
        // value for seraching
        string value;
        //fieldIndex to send for serachValue
        int fieldIndex;
        try
        {
            //parseLineImmune for not going thourgh " "
            parser.parseLineImmune(line);
            //parser.printVector();
            parser.setIterBegin();
            //check the commands if it has an error
            if(checkCommands(parser, value, fieldIndex)){
                fwrite << line << endl;
                searchValue(value, fieldIndex, fwrite);
            }
            else{
                //sorting by using lambda function
                sort(datas.begin(), datas.end(), [&](const vector<Field*>& vec1, const vector<Field*>& vec2){
                    return compareByField(vec1, vec2, fieldIndex);
                });
                fwrite << line << endl;
                writeDatasToFile(fwrite);
            }

        }
        catch (WrongCommandException& e) {
            fwrite << e.what() << endl << line << endl;
        }
        
    
    }

    
}

//delete the datas
void Catalog::deleteDatas(){
    for (auto& vec : datas) {
        for (auto& data : vec) {
            delete data;
        }
        vec.clear();
    }
    datas.clear();
}

//checking the commands
bool Catalog::checkCommands(Parse& parser, string&  value, int& fieldIndex){
    bool res = true;

    // if the vector size is not greater than 1 it is not valid command
    if(parser.getVectorSize() <= 1)
        throw WrongCommandException();

    parser.setIterBegin();
    //the first element has to be search or command and it has to be 4 or 2 
    if(parser.getVectorSize() == 4 && parser.getElement() == "search"){
        value = parser.getElement();
        //third needs to be in
        if(parser.getElement() == "in" ){
            //last supposed to be a field
            fieldIndex = isField(parser.getElement());
            if(fieldIndex == -1)
                throw WrongCommandException();
        }
        else
            throw WrongCommandException();
    }
    //sort has 2 element 
    else if(parser.getVectorSize() == 2 && parser.getElement() == "sort"){
        fieldIndex = isField(parser.getElement());
        if(fieldIndex == -1)
            throw WrongCommandException();
        res = false;
    }
    else
        throw WrongCommandException();


    return res;
}

//isField whether checks the given str is a field or not
int Catalog::isField(const string& str){
    int found = -1;

    for(int i = 0; i < fields.size(); i++){
        if(fields[i].getName() == str)
            found = i;
    }
    
    return found;
}

#endif