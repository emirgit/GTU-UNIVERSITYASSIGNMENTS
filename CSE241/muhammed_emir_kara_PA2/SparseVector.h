#ifndef _SPARSEVECTOR_H_
#define _SPARSEVECTOR_H_


#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//struct data to keep index and dobule value
struct data{
    int index;
    double d;
};

class SparseVector{
    private:
    // my private variables
        vector<struct data> allData;
        int maxIndex;
    public:
    // constructors 
        SparseVector();
        SparseVector(vector<struct data> dataVector, int index);
        SparseVector(string text);
        //getter and setter
        void addData(struct data d);
        int getMaxIndex() const;
        int getVectorSize() const;
        // operator overloading
        friend const SparseVector operator+(const SparseVector& v1, const SparseVector& v2);
        friend const SparseVector operator-(const SparseVector& v1, const SparseVector& v2);
        friend const SparseVector operator-(const SparseVector& v);
        friend ostream& operator<<(ostream& out, const SparseVector& v);
        // dot product
        friend const double dot(const SparseVector& v1, const SparseVector& v2);
        // friend class to acces the private variable in the mother class
        friend class SparseMatrix;
};

#endif 