#include<iostream>
#include<string>

using namespace std;

template<class T, class V>
class Pair{
    public:
        Pair();
        Pair(T firstValue, V secondValue);
        void setFirst(T newValue);
        void setSecond(V newValue);
        T getFirst() const;
        V getSecond() const;

    private:
        T first;
        V second;
};

template<class T, class V>
Pair<T, V>::Pair(T firstValue, V secondValue){
    first = firstValue;
    second = secondValue;
}

template<class T, class V>
void Pair<T, V>::setFirst(T newValue){
    first = newValue;
}

template<class T, class V>
void Pair<T, V>::setSecond(V newValue){
    second = newValue;
}

template<class T, class V>
T Pair<T, V>::getFirst() const{
    return first;
}

template<class T, class V>
V Pair<T, V>::getSecond() const{
    return second;
}

int main(){

    Pair<char, char> p('A', 'B');
    cout << "First is " << p.getFirst() << endl;
    p.setFirst('Z');
    cout << "First changed to " << p.getFirst() << endl;
    cout << "The pair is: " << p.getFirst() << ", " << p.getSecond() << endl;

    Pair<int, string> p2(34,"Bill");
    Pair<string, int> p3("Bill", 34);

    cout << "The pair is: " << p2.getFirst() << ", " << p2.getSecond() << endl;
    return (0);
}
