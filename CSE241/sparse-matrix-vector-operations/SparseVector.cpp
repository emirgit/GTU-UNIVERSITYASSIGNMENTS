#ifndef _SPARSEVECTOR_
#define _SPARSEVECTOR_

#include "SparseVector.h"

// default constructor in case of error
SparseVector::SparseVector(){
    maxIndex = 0;
}

// to initiliaze sparse vector with dataVector and index
SparseVector::SparseVector(vector<struct data> dataVector, int index) : allData(dataVector), maxIndex(index){
    /*Intentionally empty*/
}

//reading vector from a file
SparseVector::SparseVector(string text){

    /*
    cinfromfile a ifstream object that allow me to read a file
    int 'a' to store index temporarily for vector
    double 'b' to store double temporarily for vector 
    char c is auxiliary i*/
    ifstream cinfromfile;
    int a;
    double b;
    char c;
    cinfromfile.open(text);

    // if file can be open, put the datas to vector
    if (cinfromfile.is_open()){

        while(cinfromfile >> a >> c >> b)
            allData.push_back({a, b});

        /*while(!check_errors(&cinfromfile)){

            // read the datas and store them to vector
            cinfromfile >> a >> c >> b;
            allData.push_back({a, b});

        }*/
        maxIndex = a;
    }

    cinfromfile.close();

}

// addData to vector
void SparseVector::addData(struct data d){
    allData.push_back(d);
}

//getter
int SparseVector::getMaxIndex() const{
    return maxIndex;
}

//getter
int SparseVector::getVectorSize() const{
    return allData.size();
}

//operator overloading
const SparseVector operator+(const SparseVector& v1, const SparseVector& v2){

    // to be sure v1 max index greater or equal than v1
    if(v2.maxIndex > v1.maxIndex){
        return v2 + v1;
    }

    //Two pointer approach to store the values
    vector<struct data> vector;
    unsigned int i1 = 0, i2 = 0;

    /*
    if the index is not equal put the vector and increasing the index
    if sum is 0 don't put that vector

    otherwise just push the vector that has the minimum index
    */
    while (i1 < v1.allData.size() && i2 < v2.allData.size()){
        
        if (v1.allData[i1].index < v2.allData[i2].index){
            vector.push_back(v1.allData[i1]);
            i1++;
        }
        else if (v1.allData[i1].index > v2.allData[i2].index){
            vector.push_back(v2.allData[i2]);
            i2++;
        }
        else{
            double sum = v1.allData[i1].d + v2.allData[i2].d;
            if (sum != 0)
                vector.push_back({v1.allData[i1].index, sum});
            i1++;
            i2++;
        }
    }

    // v1 is greater than v2 because I return the array as v2 + v1 in case v2 is greater than v1
    // put the rest of value 
    while(i1 < v1.allData.size()){
        vector.push_back(v1.allData[i1]);
        i1++;
    }

    return SparseVector(vector, v1.maxIndex);
}
const SparseVector operator-(const SparseVector& v1, const SparseVector& v2){

    vector<struct data> vector;
    // two pointer to fill vector
    unsigned int i1 = 0, i2 = 0;

    while (i1 < v1.allData.size() && i2 < v2.allData.size()){

        // if index is equal put the sub of two vector
        //Otherwise, make the proper operation by the current vector index
        if (v1.allData[i1].index < v2.allData[i2].index){
            vector.push_back(v1.allData[i1]);
            i1++;
        }
        else if (v1.allData[i1].index > v2.allData[i2].index){
            vector.push_back({v2.allData[i2].index, -v2.allData[i2].d});
            i2++;
        }
        else{
            double sub = v1.allData[i1].d - v2.allData[i2].d;
            if (sub != 0)
                vector.push_back({v1.allData[i1].index, sub});
            i1++;
            i2++;
        }
    }

    // it is not clear which is greater than other 
    // so find it and put the rest datas to vector
    int max;
    if (v1.allData.size() > i1){
        while(i1 < v1.allData.size()){
            vector.push_back(v1.allData[i1]);
            i1++;
        }
        max= v1.maxIndex;
    }
    else {
        while(i2 < v2.allData.size()){
            vector.push_back({v2.allData[i2].index, -v2.allData[i2].d});
            i2++;
        }
        max= v2.maxIndex;
    }



    return SparseVector(vector, max);
}


const SparseVector operator-(const SparseVector& v){
    vector<struct data> vector;
    unsigned int i = 0;

    //taking all values and store the negative ones again 
    while(i < v.allData.size()){
        vector.push_back({v.allData[i].index, -v.allData[i].d});
        i++;
    }

    return SparseVector(vector, v.maxIndex);
}


// overloading operator by the wanted format in pdf
ostream& operator<<(ostream& out, const SparseVector& v){
    unsigned int i = 0;
    // traverse in matrix and change the datas by negating
    while(i < v.allData.size()){
        out << v.allData[i].index << ":" << v.allData[i].d << " ";
        i++;
    }

    return out;
}

// basic dot product
const double dot(const SparseVector& v1, const SparseVector& v2){
    unsigned int i1 = 0, i2 = 0;
    double dotProduct = 0;

    // If there is a 0 in current index of one of the vectors, the multiplication will be 0
    // Thus, it is enough to multiply the available 2 index
    while (i1 < v1.allData.size() && i2 < v2.allData.size()){
        // if index is same multiply the element of the vector and shift the indexes
        if (v1.allData[i1].index == v2.allData[i2].index){
            dotProduct += v1.allData[i1].d * v2.allData[i2].d;
            i1++;
            i2++;
        }
        else if (v1.allData[i1].index < v2.allData[i2].index)
            i1++;
        else
            i2++;
    }

    return dotProduct;
}

#endif 