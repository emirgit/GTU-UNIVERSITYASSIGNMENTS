#include<iostream>

using namespace std;

//my class
class MyInteger {

    private:
        int x;

    public:
        MyInteger() : x(0){
            // Intentionally empty
        }
        MyInteger(int x) : x(x){
            // Intentionally empty
        }

        int GetInt() {return x;}
        void SetInt(int newnum) { x = newnum;}

        const int operator [](int i){
            int temp = x;
            int res = temp % 10;

            if (i >= 0){
                while (temp > 0 && i > 0){
                    temp /= 10;
                    res = temp % 10;
                    i--;
                }
            }
            else {
                cout << "Illegal index value. \n";
                return -1;
            }

            if (temp == 0){
                res = -1;
            }

            return res;
        }
};


int main(){
    MyInteger num(418);
    cout << num[0] << " " << num[1] << " " << num[2] << endl;
    cout << num[3] << endl;
    cout << num[-1] << endl;
    return 0;
}

/*
#include<stdlib>


Code Of Given in PS

class MyInteger{
    private:
        int num;

    public :
        MyInteger();
        MyInteger(int newint);
        void SetInt(int newint);
        int GetInt();
        int operator[](int index);
};


MyInteger::MyInteger(){
    num = 0;
}

MyInteger::MyInteger(int newnum){
    num = newnum;
}


MyInteger::SetInt(int newnum){
    num = newnum;
}

MyInteger::GetInt(){
    return (num);
}

int MyInteger:: operator[](int index){

    int temp;

    if (index < 0)
    {
        cout << "Illegal index value. \n";
        return -1;
    }
    else {
        temp = (int) (num / pow(10, index));

        return (temğ % 10);
    }
}
*/