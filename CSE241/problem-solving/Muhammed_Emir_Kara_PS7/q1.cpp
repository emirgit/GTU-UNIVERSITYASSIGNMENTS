#include<iostream>
#include <vector>
#include <string>

using namespace std;

template<class T>
class Set{
    public:
        Set();
        void add(T newItem);
        int getSize();
        T* getArray();
    private:
        vector<T> data;
};

template<class T>
Set<T>::Set(){

}

template<class T>
void Set<T>::add(T newItem){
    bool found = false;
    int i;

    for(i = 0; i < data.size() && (found == false); i++){
        if (data[i] == newItem)
            found = true;
    }

    if(!found)
    data.push_back(newItem);


}

template<class T>
int Set<T>::getSize(){
   return data.size();
}

template<class T>
T* Set<T>::getArray(){
   T* dataArray = new T[data.size()];
   int i;

   for(i = 0; i < data.size(); i++){
        dataArray[i] = data[i];
   }

   return dataArray;
}

int main(){
    Set<int> s1;
    Set<string> s2;
    int* intArray = NULL;
    string* stringArray = NULL;
    int i;

    s1.add(10);
    s1.add(20);
    s1.add(15);
    s1.add(20);
    intArray = s1.getArray();
    cout << "Set one has " << s1.getSize() << " items. Here they are: " << endl;
    for(i = 0; i < s1.getSize(); i++){
        cout << intArray[i] << endl;
    }
    
    if(intArray != NULL)
        delete[] intArray;

    s2.add("butter");
    s2.add("hamburgers");
    s2.add("pizza");
    s2.add("hotdogs");
    s2.add("pizza");

    stringArray = s2.getArray();
    cout << "Set two has " << s2.getSize() << " items. Here they are: " << endl;

    for(i = 0; i < s2.getSize(); i++){
        cout << stringArray[i] << endl;
    }

    if (stringArray != NULL)
        delete[] stringArray;

    return (0);
}




