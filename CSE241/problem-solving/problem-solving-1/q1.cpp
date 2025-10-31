#include<iostream>

using namespace std;

int is_prime(int number);

int main(){
	int i, upper = 100;

    for (i = 3; i < upper; i++)
    {
        if(is_prime(i)){
            cout << i << " ";
        }
    }
    cout << endl;
	
	
	return (0);
}

int is_prime(int number){
    int i;
    int res = 1;

    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0){
            res = 0;
        }
        
    }
    
    return res;
}