#include <iostream>
#include <fstream>
#include <string>
#include "SparseVector.h"
#include "SparseMatrix.h"
using namespace std;

int main()
{
ofstream outfile;
outfile.open("output.txt", ios::out | ios::trunc );

SparseVector a1("a1.txt");
outfile<<"a1"<<endl<<a1<<endl;

SparseVector a2("a2.txt");
outfile<<"a1"<<endl<<a2<<endl;

outfile<<"a1 + a2"<<endl<<(a1 + a2)<<endl;
//substarction operator
outfile<<"a1 - a2"<<endl<<(a1 - a2)<<endl;

outfile<<"-a1"<<endl<<-a1<<endl;

outfile << "dot a1 a2: " << dot(a1, a2) << endl;





SparseMatrix m1("m1.txt");
outfile<<"m1"<<endl<<m1<<endl;
SparseMatrix m2("m2.txt");
outfile<<"m2"<<endl<<m2<<endl;

outfile<<"m1 + m2"<<endl<<(m1 + m2)<<endl;

outfile<<"m1 - m2"<<endl<<(m1 - m2)<<endl;

outfile<<"-m1"<<endl<<(-m1)<<endl;

outfile<<"m1 * m2"<<endl<<(m1 * m1.transpose())<<endl;

outfile<<m2.transpose()<<endl;

outfile.close();

return 0;
}