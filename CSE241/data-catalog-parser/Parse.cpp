#ifndef _PARSE_
#define _PARSE_

// parse.cpp
#include "Parse.h"
//constructor
Parse::Parse(char del) : del(del) {}

//line parser
void Parse::parseLine(const string& line) {
    //iss line used to parse the string
    istringstream iss(line);
    string token;
    
    //token is the parsed element
    while (getline(iss, token, del)) {
        //push it
        v.push_back(token);
    }
}

void Parse::parseLineImmune(const string& line) {
    istringstream iss(line);
    string token;
    
    while (getline(iss, token, del)) {

        //if the front is '"' make it immune
        if(token.front() == '"'){
            int size = token.size();

            //continue reading until one of the token has '"'
            if(size > 1){
                if(token[size - 1] == '"'){
                    if(size == 2)
                        v.push_back("");
                    else
                        v.push_back(token.substr(1, size - 2));
                }
                else{
                    string str = token.substr(1, size - 1);
                    while(getline(iss, token, del)){
                        size = token.size();
                        if(size > 1){
                            str += " ";
                            if(token.back() == '"'){
                                str += token.substr(0, size - 1);
                                v.push_back(str);
                                break;
                            }
                            else
                                str += token;
                            
                        }
                        else{
                            str += " ";
                        }
                    }

                }
            }
            else
                throw WrongCommandException();
        }
        else
            v.push_back(token);
    }
}
/*
void Parse::parseLineImmune(const string& line) {
    istringstream iss(line);
    string token;
    bool inQuotes = false;

    while (getline(iss, token, del)) {
        if (token.empty()) 
            continue;

        if (!inQuotes && token.front() == '"'){
            token.erase(token.begin()); // Remove opening quote
            inQuotes = true;
        }

        if (inQuotes) {
            if (token.back() == '"') {
                token.pop_back(); // Remove closing quote
                inQuotes = false;
            }
            v.back() += (" " + token);
        }
        else
            v.push_back(token);
    }

    if (inQuotes) {
        throw WrongCommandException();
    }
}

*/

//iterator to set begin
void Parse::setIterBegin() {
    iter = v.begin();
}

//iterator is in end 
bool Parse::iterInEnd() const {
    return iter == v.end();
}

//get element from iterator
string& Parse::getElement() {
    if (iterInEnd()) {
        throw out_of_range("End of tokens reached");
    }
    return *(iter++);
}

//getting vector of parse
vector<string> Parse::getVector(){
    return v;
}

//getting vectorsize
int Parse::getVectorSize(){
    return v.size();
}

/*
void Parse::printVector(){
    for (const auto& element : v) {
        cout << "element: " << element << "|";

        cout << endl;
    }
}*/

#endif