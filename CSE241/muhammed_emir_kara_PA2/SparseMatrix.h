#ifndef _SPARSEMATRIX_H_
#define _SPARSEMATRIX_H_

#include "SparseVector.h"
#include<sstream>

using namespace std;

//struct data to keep index and sparse vector
struct SpVector{
    int row;
    SparseVector v;
};


class SparseMatrix{
    private:
        // my private variables
        vector<struct SpVector> allSpVecs;
        int maxRow;
    public:
    // constructors 
        SparseMatrix();
        SparseMatrix(string text);
        SparseMatrix(vector<struct SpVector>  SVector, int max);
        // operator overloading
        friend const SparseMatrix operator+(const SparseMatrix& m1, const SparseMatrix& m2);
        friend const SparseMatrix operator-(const SparseMatrix& m1, const SparseMatrix& m2);
        friend const SparseMatrix operator-(const SparseMatrix& m);
        friend ostream& operator<<(ostream& out,const SparseMatrix& m);
        friend const SparseMatrix operator*(const SparseMatrix& m1, const SparseMatrix& m2);
        //transpose
        const SparseMatrix transpose() const;
        
};


#endif 