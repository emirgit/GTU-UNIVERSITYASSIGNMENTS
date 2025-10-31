#include<iostream>

using namespace std;

class HotDogStand{ 
    private:
        static int totalSold;
        int ID;
        int soldStand;
    public:
        HotDogStand() {
            ID = 0;
            soldStand = 0;
        };
        HotDogStand(int x, int y){
            ID = x;
            soldStand = y;
        };
        int getID() {return ID;};
        void setID(int id) {ID = id;}
        void JustSold() {
            totalSold++;    
            soldStand++;
        }
        int getNumSold() {return soldStand;}
        static int getTotalSold() {return totalSold;}

};

//special using because HotDogStand is private so without using int it will give an error
int HotDogStand::totalSold = 0;

int main(){
    HotDogStand stand1(1,0), stand2(2,0), stand3(3,0);

    stand1.JustSold();
    stand2.JustSold();
    stand3.JustSold();

    cout << "Stand " << stand1.getID() << " sold " << stand1.getNumSold() << endl;
    cout << "Stand " << stand2.getID() << " sold " << stand2.getNumSold() << endl;
    cout << "Stand " << stand3.getID() << " sold " << stand3.getNumSold() << endl;

    cout << "Total sold = " << stand1.getTotalSold() << endl;
    cout << "Total sold = " << HotDogStand::getTotalSold() << endl;
    cout << endl;

    stand3.JustSold();
    stand1.JustSold();

    cout << "Stand " << stand1.getID() << " sold " << stand1.getNumSold() << endl;
    cout << "Stand " << stand2.getID() << " sold " << stand2.getNumSold() << endl;
    cout << "Stand " << stand3.getID() << " sold " << stand3.getNumSold() << endl;
    cout << "Total sold = " << stand1.getTotalSold() << endl;
    cout << endl;


	return (0);
}