#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int numberOfDigits(int number){
    int counter = 0;

    while (number != 0){
        number /= 10;
        counter++;
    }

    return counter;
}

void fillArray(char* str, int size, int number){
    int i;
    for (i = 0; i < size; i++){

        str[i] = ((number % 10) + '0');
        number /= 10;
    }
    str[size] = '\0';

    
}

void sum(char* store1, char* store2, int LengthBig, int LengthSmall){

    //Hocam soruuy yanlış anladığım için 10 a indirdim
    //çünkü aldığım değer string değil integer 
    char res[10];
    int i, sum, extra = 0;

    for (i = 0; i < LengthSmall; i++){
        sum = (store1[i] - '0') + (store2[i] - '0') + extra;
        res[i] = ((sum % 10) + '0');
        extra = sum / 10;
    }

    for (i = LengthSmall; i < LengthBig; i++){
        sum = (store1[i] - '0') + extra;
        res[i] = ((sum % 10) + '0');
        extra = sum / 10;
    }
    
    if ((LengthBig + 1) == 10 && extra != 0){
        cout << "Integer Overflow" << endl;
        return ;
    }
    
    
    for (i = LengthBig; i >= 0; i--){
        cout << res[i];
    }
    cout << endl;
    
}

int main(){
    //int num1 and num2
    int num1, num2;
    // max digit (20) + null (1) = 21
    char store1[21], store2[21];
    // length of numbers
    int length1, length2;
    
    cout << "The first number :";
    cin >> num1;
    cout << "The second number :";
    cin >> num2;

    length1 = numberOfDigits(num1);
    length2 = numberOfDigits(num2);
    fillArray(store1, length1, num1);
    fillArray(store2, length2, num2);


    if (length1 > length2){
        sum(store1, store2, length1, length2);
    }
    else {
        sum(store2, store1, length2, length1);
    }
    
    

    
	
	return (0);
}
