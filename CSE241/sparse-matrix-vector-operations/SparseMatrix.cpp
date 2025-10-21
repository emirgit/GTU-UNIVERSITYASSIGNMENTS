#ifndef _SPARSEMATRIX_
#define _SPARSEMATRIX_

#include "SparseMatrix.h"

// check errors to read from a file , it is given by pdf
int check_errors(ifstream* f) {
    int stop = 0;
    if (f->eof()) {
    // EOF after std::getline() is not the criterion to stop processing
    // data: In case there is data between the last delimiter and EOF,
    // getline() extracts it and sets the eofbit.
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


// my default constructor
SparseMatrix::SparseMatrix(){
    maxRow = 0;
}

// my set constructor
SparseMatrix::SparseMatrix(vector<struct SpVector>  SVector, int max): allSpVecs(SVector), maxRow(max){
/*Intentionally empty*/
}

//my constructor reads from a file
SparseMatrix::SparseMatrix(string text){

    /*
    int 'a' to store index temporarily for vector
    double 'b' to store double temporarily for vector 
    char c is auxiliary i
    */
    ifstream f(text);
    int maxIndex = -1;
    int row;
    int a;
    double b;
    char c;
    string line;

    if(f.is_open()){
        while(1){
            getline(f, line);
            if (check_errors(&f)) {
                //skip the data processing and break
                break;
            }
            // This is the actual operation on the data obtained and we want to
            // protect it from errors during the last IO operation on the stream
            stringstream ss(line);

            // index of row the first element of line
            ss >> row;

            SparseVector curVec;

            while(ss >> a >> c >> b)
                curVec.addData({a, b});

            if (maxIndex < a)
                maxIndex = a;
             
            allSpVecs.push_back({row, curVec});
        }

        //to make it exact matrix(rectangular), because maxIndex of vector is differents
        for(unsigned int i = 0; i < allSpVecs.size(); i++){
            allSpVecs[i].v.maxIndex = maxIndex;
        }

        maxRow = row;
    }

    f.close();
}

// operator + with the same logic SparseVector
const SparseMatrix operator+(const SparseMatrix& m1, const SparseMatrix& m2){
    unsigned int i1 = 0, i2 = 0;
    vector<struct SpVector> tempVec;

    if (m1.maxRow < m2.maxRow)
        return m2 + m1;
    
    while(i1 < m1.allSpVecs.size() && i2 < m2.allSpVecs.size()){
        if(m1.allSpVecs[i1].row < m2.allSpVecs[i2].row){
            tempVec.push_back({m1.allSpVecs[i1].row, m1.allSpVecs[i1].v});
            i1++;
        }
        else if (m1.allSpVecs[i1].row > m2.allSpVecs[i2].row){
            tempVec.push_back({m2.allSpVecs[i2].row, m2.allSpVecs[i2].v});
            i2++;
        }
        else {
            SparseVector sparseVector = m1.allSpVecs[i1].v + m2.allSpVecs[i2].v;
            cout << m1.allSpVecs[i1].v << m2.allSpVecs[i2].v << endl;
            if (sparseVector.getVectorSize() != 0)
                tempVec.push_back({m1.allSpVecs[i1].row, sparseVector});
            i1++;
            i2++;
        }
    }

    while(i1 < m1.allSpVecs.size()){
        tempVec.push_back({m1.allSpVecs[i1].row, m1.allSpVecs[i1].v});
        i1++;
    }


    return SparseMatrix(tempVec, m1.maxRow);
}


// operator - with the same logic SparseVector
const SparseMatrix operator-(const SparseMatrix& m1, const SparseMatrix& m2){
    unsigned int i1 = 0, i2 = 0;
    vector<struct SpVector> tempVec;
    while(i1 < m1.allSpVecs.size() && i2 < m2.allSpVecs.size()){

        if(m1.allSpVecs[i1].row < m2.allSpVecs[i2].row){
            tempVec.push_back({m1.allSpVecs[i1].row, m1.allSpVecs[i1].v});
            i1++;
        }
        else if (m1.allSpVecs[i1].row > m2.allSpVecs[i2].row){
            tempVec.push_back({m2.allSpVecs[i2].row, -m2.allSpVecs[i2].v});
            i2++;
        }
        else {
            SparseVector sparseVector = m1.allSpVecs[i1].v - m2.allSpVecs[i2].v;
            if (sparseVector.getVectorSize() != 0)
                tempVec.push_back({m1.allSpVecs[i1].row, sparseVector});
            i1++;
            i2++;
        }
    }
    int maxRow;
    if (i1 < m1.allSpVecs.size()){
        while(i1 < m1.allSpVecs.size()){
            tempVec.push_back({m1.allSpVecs[i1].row, m1.allSpVecs[i1].v});
            i1++;
        }
        maxRow = m1.allSpVecs[i1 - 1].row;
    }
    else {

        while(i2 < m2.allSpVecs.size()){
            tempVec.push_back({m2.allSpVecs[i2].row, -m2.allSpVecs[i2].v});
            i2++;
        }
        maxRow = m2.allSpVecs[i2 - 1].row;
    }

    return SparseMatrix(tempVec, maxRow);
}


// operator unary --  with the same logic SparseVector
const SparseMatrix operator-(const SparseMatrix& m){
    unsigned int i = 0;
    vector<struct SpVector> tempVec;

    // traverse the matrix and change the value by negating
    while(i < m.allSpVecs.size()){
        tempVec.push_back({m.allSpVecs[i].row, -m.allSpVecs[i].v});
        i++;
    }

    return SparseMatrix(tempVec, m.maxRow);
}

// operator << with the same logic SparseVector
ostream& operator<<(ostream& out,const SparseMatrix& m){
    unsigned int i = 0;
    // traverse the matrix and print it by overloading 
    while(i < m.allSpVecs.size()){
        out << m.allSpVecs[i].row << " " << m.allSpVecs[i].v << endl;
        i++;
    }

    return out;
}

//multiplication 
const SparseMatrix operator*(const SparseMatrix& m1, const SparseMatrix& m2){

    // if the column of the first vector and the row of the second vector is not same, 
    // we cannot do this operation
    int maxRow = m1.maxRow;
    int maxCol = m2.allSpVecs[0].v.getMaxIndex();

    if (maxRow != maxCol) {
        // matrix multiplication cannot apply, return empty SparseMatrix
        return SparseMatrix();
    }
    /*
    logic take the transpose of the second matrix
    and apply dot product to matrix vector by vector
    after that store the new datas to vector and after matrix
    if result of dotProduct is zero that's mean we shouldn't store it in vector
    */
    SparseMatrix transposed = m2.transpose();
    vector<struct SpVector> res;
    int i, j;
    
    for(i = 0; i < m1.allSpVecs.size(); i++){
        vector<struct data> rowVec;
        for(j = 0; j < transposed.allSpVecs.size(); j++){
            double dotProduct = dot(m1.allSpVecs[i].v, transposed.allSpVecs[j].v);

            if (dotProduct != 0) {
                rowVec.push_back({transposed.allSpVecs[j].row, dotProduct});
            }
        }
        // if rowVec empty , we shouldn't add it to matrox
        if (!rowVec.empty()) {
            res.push_back({m1.allSpVecs[i].row, SparseVector(rowVec, maxCol)});
        }
    }
    //return the matrix
    return SparseMatrix(res, maxCol);
}

//transposing of a matrix
const SparseMatrix SparseMatrix::transpose() const{
    //tempVect is to acces allSpVecs
    //res to create the matrix
    //maxCol to make the matrix with the same size
    vector<struct SpVector> res;
    vector<struct SpVector> tempVec = allSpVecs;
    int maxCol = tempVec[0].v.maxIndex;

    // find the max column by searchin column by colum
    for(unsigned int i = 1; i < allSpVecs.size(); i++){
        if(allSpVecs[i].v.maxIndex > maxCol)
            maxCol = allSpVecs[i].v.maxIndex;
    }

    int col, i;

    // it is used to convert vector as column not row
    for (col = 0; col <= maxCol; col++) {
        vector<struct data> spData;

        for (i = 0; i < tempVec.size(); i++) {
            //if vector is not empty check the col and index
            if (!tempVec[i].v.allData.empty() && tempVec[i].v.allData[0].index == col) {
                //if it is found, we can push it to vector because it is non-zero
                spData.push_back({tempVec[i].row, tempVec[i].v.allData[0].d});
                tempVec[i].v.allData.erase(tempVec[i].v.allData.begin());
            }
        }
        //if spdata not empty push the data to vector and push vector to matrix
        if (!spData.empty()) {
            res.push_back({col, SparseVector(spData, maxRow)});
        }
    }

    //return a Matrix object
    return SparseMatrix(res, maxCol);
}



/*
I wrote this before, But I decided to use optimized version the one above 
const SparseMatrix SparseMatrix::transpose(){
    vector<struct SpVector> res;
    vector<struct SpVector> tempVec = allSpVecs;
    int vectorSize;
    int maxCol = allSpVecs[0].v.maxIndex;

    for(int i = 0; i < allSpVecs.size(); i++){

        int minIndex = 2147483647;
        vector<struct data> spData;
        int counter = 0;
        for(int j = 0; j < tempVec.size(); j++){

            if(!tempVec[j].v.allData.empty()){

                if (minIndex > tempVec[j].v.allData[0].index){
                    minIndex = tempVec[j].v.allData[0].index;
                }
            }
        }

        for(int j = 0; j < tempVec.size(); j++){

            if(!tempVec[j].v.allData.empty()){

                if (minIndex == tempVec[j].v.allData[0].index;){
                    spData.push_back({tempVec.row, tempVec[j].v.allData[0].d});
                    tempVec[j].v.allData.erase(tempVec[j].v.allData.begin());;
                }
            }
        }


        res.push_back({minIndex, SparseVector(spData, maxCol)});

    }

    return SparseMatrix(res, allSpVecs[0].v.getMaxIndex());
}
*/




#endif 
