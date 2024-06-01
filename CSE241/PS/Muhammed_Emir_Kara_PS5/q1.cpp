#include<iostream>
using namespace std;

class Polynomial{
    public:
        Polynomial();
        Polynomial(const Polynomial&);
        Polynomial(double coefficient[], int size);
        ~Polynomial();
        //double& operator[](int degree);
        const double& operator[](int degree) const;

        const Polynomial& operator=(const Polynomial& rhs);

        int mySize();

        friend double evaluate(const Polynomial& ploy, double arg);
        friend Polynomial operator+(const Polynomial& lsh, const Polynomial& rhs);
        friend Polynomial operator-(const Polynomial& lsh, const Polynomial& rhs);
        friend Polynomial operator*(const Polynomial& lsh, const Polynomial& rhs);

        //double Polynomial::eval(double arg);

    private:
        double *coef;
        int size;
};

int Polynomial::mySize(){
    return size;
}

Polynomial::Polynomial() : coef(0), size(0){
    //deliberately empty
}

const Polynomial& Polynomial::operator=(const Polynomial& rhs){
    if (rhs.coef == coef)
        return rhs;
    else {
        delete [] coef;
        coef = new double[rhs.size];
        for(int i = 0; i < rhs.size; i++)
            coef[i] = rhs.coef[i];
        size = rhs.size;

    }
    return rhs;
}

Polynomial::Polynomial(const Polynomial& rhs) : size(rhs.size){
    coef = new double[rhs.size];
    for(int i = 0; i < rhs.size; i++)
        coef[i] = rhs.coef[i];
}

Polynomial::Polynomial(double coefficient[], int newSize) : size(newSize){
    coef = new double[size];
    for(int i = 0; i < size; i++)
        coef[i] = coefficient[i];
}

Polynomial::~Polynomial(){
    delete[] coef;
}

const double& Polynomial::operator[](int degree) const{
    return coef[degree];
}

double max(double lhs, double rhs){
    return (lhs > rhs) ? lhs : rhs;
}

Polynomial operator+(const Polynomial& lsh, const Polynomial& rhs){
    const int sumSize = max(lsh.size, rhs.size);
    double* sumCoefs = new double[sumSize];

    for(int i = 0; i < sumSize; i++)
        sumCoefs[i] = lsh.coef[i] + rhs.coef[i];

    Polynomial q(sumCoefs, sumSize);
    delete[] sumCoefs;

    return q;
}

Polynomial operator-(const Polynomial& lsh, const Polynomial& rhs){
    const int sumSize = max(lsh.size, rhs.size);
    double* sumCoefs = new double[sumSize];

    for(int i = 0; i < sumSize; i++)
        sumCoefs[i] = lsh.coef[i] - rhs.coef[i];
/*
    Polynomial q(sumCoefs, sumSize);
    delete[] sumCoefs;
*/
    return Polynomial(sumCoefs, sumSize);
}

Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs){
    int i, j;
    int prodSize = lhs.size + rhs.size;
    double* prodCoefs = new double[prodSize];

    for(i = 0; i < prodSize; i++)
        prodCoefs[i] = 0;

    for(i = 0; i < lhs.size; i++)
        for(j = 0; j < rhs.size; j++)
            prodCoefs[i + j] += lhs[i] * rhs[j];

    return Polynomial(prodCoefs, prodSize);    
}

double evaluate(const Polynomial& poly, double arg){
    double value = 0;
    int i;

    for(i = poly.size - 1; i >= 0; i--)
        value = poly[i] + arg * value;

    return value;
}

/*double Polynomial::eval(double arg){
    double value = 0;
    int i;

    for(i = size - 1; i >= 0; i--);
        value = coef[i] + arg * value;
    
    return value;
}*/

int main(){
    Polynomial empty;
    double one[] = {1};
    Polynomial One(one, 1);
    double quad[] = {3, 2, 1};
    double cubic[] = {1, 2, 0, 3};
    Polynomial q(quad, 3); // q is 3 + 2*x + x*x
    Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
    Polynomial p = q; // test copy constructor
    Polynomial r;
    r = q;
    //test operator=
    r = c;
    cout << "Polynomial q " << endl;
    {for(int i = 0; i < 3; i++)
        cout << "term with degree " << i
        << " has coefficient " << q[i] << endl;
    }
    cout << "Polynomial c " << endl;
    {for(int i = 0; i < 4; i++)
        cout << "term with degree " << i
        << " has coefficient " << c[i] << endl;
    }
    cout << "value of q(2) is " << evaluate(q, 2) << endl;
    cout << "value of p(2) is " << evaluate(p, 2) << endl;
    cout << "value of r(2) is " << evaluate(r, 2) << endl;
    cout << "value of c(2) is " << evaluate(c, 2) << endl;
    r = q + c;
    cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;
    r = q - c;
    cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;
    r = q * c;
    cout << "size of q*c is " << r.mySize() << endl;
    cout << "Polynomial r (= q*c) " << endl;
    for(int i = 0; i < r.mySize(); i++)
    cout << "term with degree " << i
    << " has coefficient " << r[i] << endl;
    cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
    return 0;
}