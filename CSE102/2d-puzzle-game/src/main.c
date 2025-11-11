#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
//defining macros as it said in PDF

//declarating the functions part1 draw part 2 gameplay part3 condition part4 game 
void draw_room(int size, int char_cord_x, int char_cord_y, int door_cord_x, int door_cord_y);
int is_gameover(int char_cord_x, int char_cord_y, int door_cord_x, int door_cord_y);
void gameplay(int size); 
void game(void);

int main(){
	game();
	return (0);
}

void draw_room(int size, int char_cord_x, int char_cord_y, int door_cord_x, int door_cord_y){
	int i,j;
	
	/*
	this is rooms for 8x8
	-----------------
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	-----------------
		
	this is i values for 8x8 room
	
	99999999999999999
	88888888888888888
	77777777777777777
	66666666666666666
	55555555555555555
	44444444444444444
	33333333333333333
	22222222222222222
	11111111111111111
	00000000000000000
	
	this is j values of 8x8 room 
	
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	
	i interval start 9 end 0 (i = size +1 ;i >= 0)
	j interval start 0 end 17 (17 not be included)(j < 2 * size + 1)
	
	for floor and top '-' will be printed 
	that's mean i = 0 and i = size + 1
	for the coordinates of the character 'C' will be printed
	for the coordinates of the door 'D' will be printed
	for the doors of rooms '|' will be printed
	that's mean j % 2 == 0 
	space will be printed for other cases
	*/
	for (i = size + 1; i >= 0; i--) {
        for (j = 0; j < 2 * size + 1 ; j++) {
            if (i == 0 || i == size + 1)
            	printf("-");
			else if (i == char_cord_y && j == char_cord_x)
				printf("C");
			else if (i == door_cord_y && j == door_cord_x)
				printf("D");
			else if (j % 2 == 0)
				printf("|");
			else
				printf(" ");
        }
        printf("\n");
    }
}

int is_gameover(int char_cord_x, int char_cord_y, int door_cord_x, int door_cord_y){
	//if the cordinates are the same ,character was able to reach to door
	if (char_cord_x == door_cord_x && char_cord_y == door_cord_y){
		return (1);
	}
	else{
		return (0);
	}
}

void gameplay(int size){
	
	int char_cord_x, char_cord_y, door_cord_x, door_cord_y, movect;
	char move;
		
	/*
	srand allow us to initialize the seed of random in each run
	if we don't use it ,program will give us same numbers 
	to prevent this we have to change seed every time
	time(NULL) give us the time since 1970 as second
	so it will change everytime 
	that's what we want
	*/
	srand(time(0));
	/*
	this is rooms for 8x8
	-----------------
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	| | | | | | | | |
	-----------------
	
	
	this is i values for 8x8 room
	99999999999999999
	88888888888888888
	77777777777777777
	66666666666666666
	55555555555555555
	44444444444444444
	33333333333333333
	22222222222222222
	11111111111111111
	00000000000000000
	
	this is j values of 8x8 room 
	
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	012345678910111213141516
	
	Avaible y axis for door and character is 1,2,3,4,5,6,7,8
	so random values have to start from 1 to n
	Avaible x axis for door and character is 1,3,5,7,9,11,13,15
	so random values have to start from 1 to 2n+1(because i
	
	rand() % size(8) will produce 0,1,2,3,4,5,6 or 7
	(rand() % size(8)) + 1 will produce 1,2,3,4,5,6,7 or 8
	that's what ý want for x axis
	2 * (rand() % size(8)) will produce 0,2,4,6,8,10,12 or 14
	2 * (rand() % size(8)) + 1 will produce 1,3,5,7,9,11,13,15
	that'S what ý want for y axis
	*/
	char_cord_y = (rand() % size) + 1;
	char_cord_x = 2 * (rand() % size) + 1;
	door_cord_y = (rand() % size) + 1;
	door_cord_x = 2 * (rand() % size) + 1;
	//if start values is equal, change it
	while (char_cord_x == door_cord_x && char_cord_y == door_cord_y){
		char_cord_x = (rand() % size) + 1;
		char_cord_y = 2 * (rand() % size) + 1;		
	}
	//moves counter
	movect = 0;
	
	//if the loops end,
	while (!is_gameover(char_cord_x, char_cord_y, door_cord_x, door_cord_y)) {
		//drawing room
		draw_room(size, char_cord_x, char_cord_y, door_cord_x, door_cord_y);
		/*
		taking the move
		It will prompt the user for a new move after each move.
		You can enter multiple move at the same tame
		it is recommended to enter one by one for a better view.
		*/
		printf("Enter move: ");
		scanf(" %c",&move);
		//I used switch because there are 5 condition (up,down,right,left,default)
		switch (move) {
			//using macro key UP = 'w'
			case UP:
				//if char_cord_y = size ,the character is at top of the room and he cannot move(size + 1 = wall)
				if (char_cord_y < size ){
					//increment the y-coordinate by 1 to move to the location above
					char_cord_y++;
				}
				else{
					printf("Character cannot move up\n");
				}
				break;
			//using macro key DOWN = 's'
			case DOWN:
				//if char_cord_y = 1 ,the character is at bottom of the room and he cannot move(0 = wall)
				if (char_cord_y > 1){
					//decrement the y-coordinate by 1 to move to the location under
					char_cord_y--;
				}
				else{
					printf("Character cannot move down\n");
				}
				break;
			//using macro key LEFT = 'a'
			case LEFT:
				//if char_cord_y = 1 ,the character is on the edge of the room and he cannot move(0 = wall)
				if (char_cord_x > 1){
					//decrement the x-coordinate by 2 to move to the location left
					char_cord_x -= 2;
				}
				else{
					printf("Character cannot move left\n");
				}
				break;
			//using macro key RIGHT = 'd'
			case RIGHT:
				//if char_cord_y = 2*size - 1,the character is on the edge of the room and he cannot move(2*size + 1 = wall)
				if (char_cord_x < 2 * size - 1 ){
					//increment the x-coordinate by 2 to move to the location right
					char_cord_x += 2;
				}
				else{
					printf("Character cannot move right\n");
				}
				break;
			default:
				printf("Invalid move\n");
		}
		//increment move counter by 1
		movect++;
	}
	//if the game over,print the last situation of room and print congratulatory address
	draw_room(size, char_cord_x, char_cord_y, door_cord_x, door_cord_y);
	printf("Congratulations, you got your character to the room in %d\n", movect);
}

void game(void){
	int size, choice;
	
	/*MENU
	I put welcome message out of the while,
	Because I didn't want players to receive a welcome message again after finishing the game once.
	*/
	printf("Welcome to the 2D puzzle game!\n");
	while (1){
		printf("1. New Game\n");
		printf("2. Help\n");
		printf("3. Exit\n");
		scanf("%d", &choice);
		
		/*if (choice == 1){
			game()
		}
		else if (choice == 2){
			
		}
		else if (choice == 3){
			printf("Thanks for playing,Take care.");
			break;
		}
		else{
			printf("You entered invalid selection (Valid selections are 1, 2 and 3)");
		}
		*/
		switch (choice){
			
			//Case 1 playing game
			//enter size room as it said in PDF
			case 1:
				printf("Enter size of the room (5-10) E.g 5: ");
				scanf("%d", &size);
				while (!(size >= 5 && size <= 10)){
					printf("Invalid room size. Please enter valid room size\n");
					printf("Enter size of the room (5-10) E.g 5: ");
					scanf("%d", &size);
				}
				gameplay(size);
				break;
			
			//how to play
			case 2:
				printf("The game consists of a dark room of size NxN that you determine\n");
				printf("You manages the character who try to find the door of the room\n");
				printf("You can move one space in any of the four cardinal directions\n");
				printf("You can move to left by entering 'a'\n");
				printf("You can move to right by entering 'd'\n");
				printf("You can move to up by entering 'w'\n");
				printf("You can move to down by entering 's'\n");
				printf("You can enter multiple move at same time\n");
				printf("But each character will be drawn as if they were entered one by one to prevent moving diagonal\n");
				printf("It is recommended to enter one by one for a better view.\n");
				printf("To win the game you need to get your character to the room\n");
				printf("Warnings\n");
				printf("It is forbidden to try to pass through walls\n");
				printf("Good luck :)\n");
				break;
			//exit and goodbye massage
			case 3:
				printf("Thanks for playing,Take care.\n");
				return;
				//I didn't use exit because the function will return to main and there is no more code after game() function
				//So I think there is no need to call exit to terminate program.
			//Invalid selection
			default:
				printf("You entered invalid selection (Valid selections are 1, 2 and 3)\n");
				printf("Please enter valid selections\n");			
		}
	}
}
