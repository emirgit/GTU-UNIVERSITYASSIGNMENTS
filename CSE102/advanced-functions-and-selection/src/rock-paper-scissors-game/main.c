#include<stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	/*
	Ask the user to make a choice with choice variable
	random choice for computer choice
	ask the user whether he/she want to play again or not
	*/
	int choice,randcho;
	char p_again;
	
	/*
	srand allow us to initialize the seed of random in each run
	if we don't use it ,program will give us same numbers 
	to prevent this we have to change seed every time
	time(NULL) give us the time since 1970 as second
	so it will change everytime 
	that's what we want
	*/
	srand(time(NULL));
	//Continue loop until the user doesn't want to play again .If he/she wants ,break loop 
	while (1){
		printf("Please make a choice!\n1: Stone, 2: Paper, 3: Scissors\n");
		scanf("%d",&choice);
		/*
		the computer must select 1 2 or 3
		rand() % 3 give 0,1,2
		by adding it 1 we can reach those values
		*/
		randcho = (rand() % 3) + 1;
		/* 
		I used if-else and switch-case appropriately according to their respective needs
		for users choice ,it can have 4 option 1,2,3 or default
		but for computer it has to select 1 2 or 3 (3 option)
		So I wanted to use them mixed
		*/
		switch (choice){
			case 1:
				printf("You chose Stone. ");
				if (randcho == 1)
					printf("I chose Stone. It's a tie!\n");
				else if (randcho == 2)
					printf("I chose Paper. I won!\n");
				else
					printf("I chose Scissors. You won!\n");
				break;
			case 2:
				printf("You chose Paper. ");
				if (randcho == 1)
					printf("I chose Stone. You won!\n");
				else if (randcho == 2)
					printf("I chose Paper. It's a tie!\n");
				else
					printf("I chose Scissors. I won!\n");
				break;
			case 3:
				printf("You chose Scissors. ");
				if (randcho == 1)
					printf("I chose Stone. I won!\n");
				else if (randcho == 2)
					printf("I chose Paper. You won!\n");
				else
					printf("I chose Scissors. It's a tie!\n");
				break;
				
			default:
				printf("Invalid choice\n");
		}
		//Asking the user if he/she want play again
		printf("Do you want to play again? (Y/N)(Default or Invalid choice is Y): ");
		scanf(" %c", &p_again);
		//if not ,break the loop and program will be ended up
		if (p_again == 'N')
			break;

	}
	
	return (0);
}


