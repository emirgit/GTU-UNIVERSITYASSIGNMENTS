#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int roundSimulate(void);

int main(){
    int roundLimit = 10000;
	int round = 0;
    int winners[3] = {0};
    int win;
    srand(time(0));

    while(round < 10000){
        win = roundSimulate();
        winners[win]++;

        switch (win){
        case 0:
            cout << "Aaron won the " << round + 1 << "." << "round" << endl;
            break;
        case 1:
            cout << "Bob won the " << round + 1 << "." << "round" << endl;
            break;
        case 2:
            cout << "Charlie won the " << round + 1 << "." << "round" << endl;
            break;
        
        default:
            break;
        }
        

        round++;
    }

    cout << "Aaron won " << winners[0] << "/" << roundLimit << " duels or " << (double) winners[0] * 100 / roundLimit << " %" << endl;
    cout << "Bob won " << winners[1] << "/" << roundLimit << " duels or "  << (double) winners[1] * 100 / roundLimit << " %" << endl;
    cout << "Charlie won " << winners[2] << "/" << roundLimit << " duels or "  << (double) winners[2] * 100 / roundLimit << " %" << endl;


	
	return (0);
}

int roundSimulate(){
    bool isAAlive, isBAlive, isCAlive;
    int res, num;

    isAAlive = 1;
    isBAlive = 1;
    isCAlive = 1;



    while (isAAlive + isBAlive + isCAlive > 1){
        
        //Aaron Tour
        if (isAAlive){
            num = rand() % 3;
            if (num == 0){
                if (isCAlive){
                    isCAlive = 0;
                }
                else {
                    isBAlive = 0;
                }
            }
        }

        //Bob Tour
        if (isBAlive){
            num = rand() % 2;
            if (num == 0){
                if (isCAlive){
                    isCAlive = 0;
                }
                else {
                    isAAlive = 0;
                }
            }
        }
        //Charlie Tour
        if (isCAlive){
            if (isBAlive){
                isBAlive = 0;
            }
            else {
                isAAlive = 0;
            }
        }
    }

    if (isAAlive){
        res = 0;
    }
    else if (isBAlive){
        res = 1;
    }
    else {
        res = 2;
    }


    return res;        
}
        


