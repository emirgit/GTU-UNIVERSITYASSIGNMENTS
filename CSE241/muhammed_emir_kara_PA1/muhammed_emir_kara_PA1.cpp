#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;


//auxiliary functions
int f_strcmp(const char *str1, const char *str2);
int f_strlen(const char *str);

// length of ELEMENTLIST is 15 if we don't count null element
const char ELEMENTLIST[] = {'0', '1','2','3','4','5','6','7','8','9','a','b','c','d','e','\0'};
const int LENGTHLIST = 15;
const int ERRORNUM = -1;
// const char[] listOfElements = "0123456789abcde";

//these 3 function check the parameter entered in terminal

int checkFirstParam(const char* firstParam);
void checkAndCreate(const char* secondParam, char* secretNum);
void f_strcp(const char *secondParam, char* secretNum);

//it is the function game played after some checking applied
void game(char* secretNum);

//it checks if the guess is correct or not
int isCorrect(const char* guess);
void editGuess(char* userGuess, int size);

//it prints the error by using cerr
void printError(const char* err);

int main(int argc, char const *argv[]){

    //when the main execute, arrange the seed
    srand(time(0));
    
    if (argc == 3){
        
        // if selectedMode is equal to 1, it means "-r" 
        // if selectedMode is equal to 2, it means "-u"
        // else it is -1 that is error
        
        
        int selectedMode = checkFirstParam(argv[1]);
        if (selectedMode != ERRORNUM){
            char secretNum[16];
            switch (selectedMode){
                case 1:
                //if the given parameter is correct, create the secret number
                
                    checkAndCreate(argv[2], secretNum);
                    break;
                case 2:
                //if the secret number that user input is correct, start the game
                    if (isCorrect(argv[2])){
                        f_strcp(argv[2], secretNum);
                    }
                    else{
                        // there are 3 possible error
                        // using an element more than one (not unique)
                        // using an element is not in list 
                        // out of length of list (also not unique)
                        printError("E0");
                    }
                    
                    break;
                default:
                    //if unexpected error comes out
                    printError("E0");
                    break;
            }

            
            //game logic
            game(secretNum);



        }
        else{
            //Undefined or wrong parameters error
            printError("E0");
        }
        
    }
    else{
        //Missing parameters error
        printError("E0");
    }
 
        
	return (0);
}

void game(char* secretNum){
    //Max 50 char
    char userGuess[50];
    // i and j is element of for loops, and iter to control the number of tour the user found the number.
    int ctr1, ctr2, i, j, iter = 0;

    // numLength is the length of the secretNum
    int numLength = f_strlen(secretNum);
    char curChar;
    int curIndex;

    do{
        //taking guess from user
        cin.getline(userGuess, 50);
        //editGuess checking the array whether it have whitespace or not, and remove the whitespace
        editGuess(userGuess, 50);

        // if the source of the error is length, print E1 error
        if (f_strlen(userGuess) != numLength) {
            //printError directly exit
            printError("E1");
        }

        //initiliaazing the counters early because ctr1 will use in condition of loop
        ctr1 = 0;
        ctr2 = 0;
        //checking the Guess
        if (isCorrect(userGuess)){


            /*Logic
            finding the current character of the user's input 
            if it is found check whether it match with place (increase ctr1)
            otherwise (increase ctr 2)
            if it couldn't find it try next character
            */
            for (i = 0; i < numLength; i++){
                curChar = userGuess[i];
                curIndex = -1;
                for(j = 0; j < LENGTHLIST; j++){
                    if (secretNum[j] == curChar){
                        curIndex = j;
                        break;
                    }
                    
                }

                if (curIndex != -1){
                    if (curIndex == i)
                        ctr1++;
                    else
                        ctr2++;
                    
                }
                
            }

            //printing ctr1 and ctr2
            if (ctr1 != numLength)
                cout << ctr1 << " " << ctr2 << endl;
            
            
            
        }//else print E2 error
        else{
            cout << "E2" << endl;
        }
        

        //continue to iter until 100 round or user find the number (ctr1 == numLength)
        iter++;
    } while (iter < 100 && ctr1 != numLength);

    // if number of matched place is equal to number length, user guessed the number
    if (ctr1 == numLength){
        cout << "FOUND " << iter << endl;
    }
    else {
        cout << "FAILED\n";
    }
    

}

int checkFirstParam(const char *firstParam){
    // copying the first parameter to a string called str
    // if something went wrong, it will return -1
    int res = -1;

    // "-r" returns 1, "-u" returns 2
    if (!f_strcmp(firstParam, "-r")){
        res = 1;
    }
    else if (!f_strcmp(firstParam, "-u")) {
        res = 2;
    }
    
    return res;
}

// it is to creating list by "-r" and the inputted number
void checkAndCreate(const char* secondParam, char* secretNum){
    // converting the number from string to int by using stoi
    int numberOfDigits = stoi(secondParam);
    //initiliazing the char array with null. + 1 to guarantee null 
    int i, j, randIndex, isUsed;

    // checking if the input is in range or not.
    if (numberOfDigits < 1 || numberOfDigits > 15){
        printError("E0");
    }

    /*
    Algorithm
    it start from 0. index to fill new secret num
    it takes a rand index to take char from  ELEMENTLIST and checks if it is already used or not
    if it is not used, the char at index puts on i. index
    */


    i = 0;
    while(i < numberOfDigits){
        randIndex = rand() % LENGTHLIST;
        isUsed = 0;
        for(j = 0; j < i; j++){
            
            if (secretNum[j] == ELEMENTLIST[randIndex]){
                isUsed = 1;
                break;
            }
        }
        // if it is not used and don't put 0 when the index is 0
        if (!isUsed && !(i == 0 && ELEMENTLIST[randIndex] == '0')){
            secretNum[i] = ELEMENTLIST[randIndex];
            i++;
        }
    }
    //guarantee null
    secretNum[i] = '\0';
    
}

int isCorrect(const char* str){
    // it works like hash map, it will count the argument in inputted Secret Number 
    int check[LENGTHLIST] = {0};
    int length = f_strlen(str);

    // if length is out of range or the first element of user guess is 0, return directly error
    if (length > LENGTHLIST || length == 0 || str[0] == '0'){
        return 0;
    }
    
    //check the unique error 
    int i,j, res = 1;
    for (i = 0; i < length; i++)
    {
        for(j = 0; j < LENGTHLIST; j++){
            if (str[i] == ELEMENTLIST[j]){
                check[j]++;
                break;
            }
        }

        if (j == LENGTHLIST){
            //it found something is not in the list
            res = 0;
            break;
        }
    }

    for(i = 0; i < LENGTHLIST; i++){
        if (check[i] > 1){
            res = 0;
            break;
        }
        
    }
    
    return res;
}

void editGuess(char* userGuess, int size){
    int i, j;

    j = 0;
    for (i = 0; i < size; i++){
        // if the userGuess one of the whitespace elements like whitespace or tabs, overwrite it
        if (!(userGuess[i] == ' ' || userGuess[i] == '\t' || userGuess[i] == '\v')){
            userGuess[j] = userGuess[i];
            j++;
        }
        
    }
    //null guarantee
    userGuess[j] = '\0';
}


void printError(const char* err){
    cout << err << endl;
    exit(0);
}

int f_strcmp(const char *str1, const char *str2){
    int i;

    i = 0;
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i])
            return (1);

        i++;
    }

    return (0);
}

int f_strlen(const char *str){
	int i;
	
	i = 0;
	while (str[i] != '\0'){
		i++;
	}
	
	return (i);
}

void f_strcp(const char *secondParam, char* secretNum){
    int i;

    for (i = 0; secondParam[i] != '\0'; i++){
        secretNum[i] = secondParam[i];
    }
    secretNum[i] = '\0';
    
}