#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);

int main(){
    int humanTotalScore = 0;
    int computerTotalScore = 0;
	
    srand(time(0));
    while(humanTotalScore < 100 || computerTotalScore < 100){
        humanTotalScore += humanTurn(humanTotalScore);
        cout << "Your total score is now " << humanTotalScore << endl;
        if (humanTotalScore >= 100)
            break;

        computerTotalScore += computerTurn(computerTotalScore);
        cout << "Computer's total score is now " << computerTotalScore << endl;   
    }

    if (humanTotalScore >= 100){
        cout << "Congratulations!! You won!" << endl;
    }
    else {
        cout << "Computer won!! Try Again!" << endl;
    }
    
	
	return (0);
}

int humanTurn(int humanTotalScore){
    string userInput;
    int dice;
    int score = 0;

    while (true){
        cout << "Your current total score is " << humanTotalScore + score << " and current score is " << score << endl;
        cout << "Roll(\"r\") or hold(\"h\") :";
        cin >> userInput;

        if (userInput == "r"){
            dice = rand() % 6 + 1;
            cout << "You rolled "<< dice << endl;
            if (dice != 1){
                score += dice;
            }
            else {
                
                score = 0;
                break;
            }
        }
        else if (userInput == "h"){
            break;
        }
        else{
            cerr << "Invalid input! Input new" << endl;
        }
        
        
        // random number range 0 to 5 thus, plus 1 
        
    }
        
    return score;
}

int computerTurn(int computerTotalScore){
    int dice;
    int score = 0;

    while (score < 20){
        dice = rand() % 6 + 1;

        cout << "Computer rolled " << dice << endl;
        if (dice != 1){
            score += dice;
            cout << "Computer's current score is " << score << endl;
        }
        else {
            score = 0;
            break;
        }

        
        
        // random number range 0 to 5 thus, plus 1 
        
    }
        
    return score;

}