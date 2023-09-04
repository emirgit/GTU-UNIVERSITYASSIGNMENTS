#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ROW 3 /* minimum 3 */
#define COLUMN 2 * ROW - 1
//FOR NXN tic-tac-toe change column as 2 * row - 1 (E.g row = 3 column = 5    row = 5 column 9)
//because there is 1 space between each column to make it look good

typedef enum {
	RED, GREEN, BLUE,YELLOW, ORANGE
} Color;


/*
declarations
Since it is a declaration, only its types can be specified. char convert_case(char c) ----> char convert_case(char)
but I prefer this
*/
char convert_case(char c);
void print_tabular_format(int arr[]);
void part1(void);

Color enter_color(void);
double calculate_distance(double mixed_colors[3],const double color_vector[3]);
Color colorMixer(Color color1, Color color2 ,Color (*f_ptr)(Color mixed1, Color mixed2));
Color mix_colors(Color color1, Color color2);
void part2(void);


void clear_board(char board[ROW][COLUMN]);
void print_board(char board[ROW][COLUMN]);
int check_winner(char board[ROW][COLUMN]);
int is_board_full(char board[ROW][COLUMN]);
void part3(void);


int main(){
	
	part1();
	part2();
	part3();
	
	return (0);
}

//definitions
//this functions takes a character to convert it upper-case and will return character that was taken and converted
char convert_case(char c){
	//lower character are between 97-122 in ascii table
	c -= 32;			/*  The ASCII values for uppercase letters range from 65 to 90, 
							while the ASCII values for lowercase letters range from 97 to 122.
							So this difference is 32 */
	return (c);
}

void print_tabular_format(int arr[]){
	int i;
	
	printf("Letter Frequency:\n");
	for (i = 65; i <= 90; i++)
		printf("%c: %d\n", i, arr[i-65]);
}

void part1(void) {
	FILE *ptr;
	// there are (90(Z)-65(A) + 1 = )26 letter in ascii table(English alphabet).
	char ch,file_name[100];
	//initilization all character as 0 (A = 0. index B = 1. index .... Z = 25. index) 
	int i,arr[26] = {0};
	
	//taking the file name from user
	printf("Enter the file name: ");
	scanf("%s",file_name);
	printf("\n");
	
	//Opening an existing file(example.txt by using fopen()) with read mode
	ptr = fopen(file_name,"r");
	
	//if file not found, warn user and end this part
	if (ptr == NULL){
		printf("File not found.\nTry moving the file to the folder or entering the full path.\n");
		return ;
	}
	
	while ((ch = fgetc(ptr)) != EOF){
		/*I prefer check whether the character is lowercase or not in this function
		  In this way there will be no need to call the function again for each character */
		if (ch >= 97 && ch <= 122)
			ch = convert_case(ch);
		if (ch >= 65 && ch <= 90)
			arr[ch - 65] += 1;
	}
	//printing tabular format
	print_tabular_format(arr);
}
//modular programming for part2
//taking color in another function
Color enter_color(void){
	char input;
	
	scanf(" %c",&input);
	switch(input){
		case 'r':
			return RED;
		case 'g':
			return GREEN;
		case 'b':
			return BLUE;
		case 'y':
			return YELLOW;
		case 'o':
			return ORANGE;
		default:
			printf("Invalid color.");
			exit(1);
	}
}
//calculating distance by using euclidean distance
double calculate_distance(double mixed_colors[3],const double color_vector[3]){
	int i;
	double distance;
	
	//initilization
	distance = 0.0;
	//taking all square of all dimensions's distance
	for (i = 0; i < 3; i++){
		distance += pow((mixed_colors[i] - color_vector[i]), 2);
	}
	
	//square root of distance
	return sqrt(distance);
}

//Create a function called 'colorMixer' that takes two 'Color' enumeration
//values and a function pointer as arguments
Color colorMixer(Color color1, Color color2 ,Color (*f_ptr)(Color, Color)){
	return (*f_ptr)(color1, color2);
}

/*
The function pointer should point to a function(mix_color) that takes
two 'Color' enumeration values and returns a new 'Color' enumeration value as a result of mixing the
input colors.
*/
Color mix_colors(Color color1, Color color2){
	/*
	i for indexing
	min_index will return the index of distance that is the closest to calculated vector of mixed color
	distance[5] will store the distances of  mixed color from main vectors of colors
	vector_mixed_color[3] the values of the mixed color 
	const double colors_vector[][3] is values of the main colors
	*/
	int i, min_index;
	double distance[5], vector_mixed_color[3], min;
	const double colors_vector[][3] = {
    {1.0, 0.0, 0.0},		// RED
    {0.0, 1.0, 0.0},		// GREEN
    {0.0, 0.0, 1.0},		// BLUE
    {0.5, 0.5, 0.0},		// YELLOW
    {0.5, 0.4, 0.2}			// ORANGE
	};
	
	//calculating all dimension of mixed vector
	for(i = 0; i < 3; i++){
		vector_mixed_color[i] = (colors_vector[color1][i] + colors_vector[color2][i]) / 2;
	}
	//calculating all elements of distance array by using calculate_distance function
	for(i = 0; i < 5; i++){
		distance[i] = calculate_distance(vector_mixed_color, colors_vector[i]);
	}
	
	//finding minimum value and its index in array 
    min = distance[0];
    for (i = 1; i < 5; i++) {
        if (distance[i] < min) {
            min = distance[i];
            min_index = i;
        }
    }
    
    //finding the closest color by looking min_index
    switch (min_index){
    	case 0:
            return RED;
        case 1:
            return GREEN;
        case 2:
            return BLUE;
        case 3:
            return YELLOW;
        case 4:
            return ORANGE;
	}
}

void part2(void) {
	//c1 c2 and mixed color variable
	Color c1, c2, mixed;
	//taking color 1 from user
	printf("Enter color 1 (r,g,b,y,o): ");
	c1 = enter_color();
	//taking color 2 from user
	printf("Enter color 2 (r,g,b,y,o): ");
	c2 = enter_color();
	
	printf("Mixed Color: ");
	mixed = colorMixer(c1, c2, mix_colors);
	
	switch(mixed) {
        case RED:
            printf("RED [1, 0, 0]\n");
            break;
        case GREEN:
            printf("GREEN [0, 1, 0]\n");
            break;
        case BLUE:
            printf("BLUE [0, 0, 1]\n");
            break;
        case YELLOW:
            printf("YELLOW [0.5, 0.5, 0.0]\n");
            break;
        case ORANGE:
            printf("ORANGE [0.5, 0.4, 0.2]\n");
            break;
    }
}

void clear_board(char board[ROW][COLUMN]){
	int row, column;
	/*
	if column is a multiple of 2,put underscore character('_' ascii 95) I will mention about that as a space in XOX
	else print space character (' ' ascii 32)
	*/
	for (row = 0; row < ROW; row++){
		for (column = 0; column < COLUMN; column++){
			if (column % 2 == 0)
				board[row][column] = '_';
			else
				board[row][column] = ' ';
		}
	}
}

void print_board(char board[ROW][COLUMN]) {
	int row, column;
	/*
	printing two dimensinol array basically by using nested loop
	*/
	for (row = 0; row < ROW; row++){
		for (column = 0; column < COLUMN; column++){
			printf("%c", board[row][column]);
		}
		printf("\n");
	}	
}

int check_winner(char board[ROW][COLUMN]){
	int row, column;
	char current_ch;
	
	//checking right diagonal for the character at the top left of the array
	if (board[0][0] != '_'){
		
		current_ch = board[0][0];
		column = 2;
		row = 1;
		while (column < COLUMN && row < ROW){
			if (board[row][column] != current_ch){
				current_ch = 0;
				break;
			} 
			row++;
			column +=2;
		}
	if (current_ch != 0)
		return current_ch;
	}
	
	//checking left diagonal for the character at the top right of the array
	if (board[0][COLUMN - 1] != '_'){
		current_ch = board[0][COLUMN - 1];
		column = COLUMN - 3;
		row = 1;
		while (column >= 0 && row < ROW){
			if (board[row][column] != current_ch){
				current_ch = 0;
				break;
			} 
			row++;
			column -= 2;
		}
		
		if (current_ch != 0)
			return current_ch;
	}
	//checking whether all entries in that line is same or not
	//if it is ,return current_ch else look others
	for (row = 0; row < ROW; row++){
		if (board[row][0] != '_'){
			current_ch = board[row][0];
			for (column = 2; column < COLUMN; column += 2){
				if (board[row][column] != current_ch){
					current_ch = 0;
					break;
				}
			}
			if (current_ch != 0)
				return current_ch;
		}
	}
	//checking whether all entries in that column is same or not
	//if it is ,return current_ch else look others
	for (column = 0; column < COLUMN; column += 2){
		if (board[0][column] != '_'){
			current_ch = board[0][column];
			for (row = 1; row < ROW; row++){
				if (board[row][column] != current_ch){
					current_ch = 0;
					break;
				}
			}
			if (current_ch != 0)
				return current_ch;	
		}
	}
	return (1);
}

int is_board_full(char board[ROW][COLUMN]) {
	int row, column;
	/*
	this function is basically nested loops for array
	if there is an space('_'),board is not full return 1
	*/
	for (row = 0; row < ROW; row++){
		for (column = 0; column < COLUMN; column += 2){
			if (board[row][column] == '_')
				return (1);
		}
	}
	
	return (0);
}

void part3(void) {
	/*
	board is 2d array that the game will be played
	play_again will ask the user want to play again
	row is row index of array
	column is column index of array (nested mostly)
	draw_or_win is control variable to check win or draw
	*/
	char board[ROW][COLUMN], play_again;
	int row, column, player, draw_or_win;
	
	//initilization for play_again vaariable to enter loop
	play_again = 'Y';
	while (play_again != 'N'){
		//create a board by calling clear_board function after that it will clear the array
		clear_board(board);
		//which player will be start firstly
		player = 1;
		//initilization for draw_or_win like play_again
		draw_or_win = 1;
		//is_board_full function will check if array is full
		while ((draw_or_win == 1)  && is_board_full(board)) {
			/*
			player 1 print x
			player 2 print o
			I didn't changed this because I didn't want the code to be hard to read
			
			*/
			if (player == 1) {
				//taking variable from users
				printf("Player %d (X), enter your move (row,col): ", player);
				scanf("%d %d", &row, &column);
				/*
				checking variable is in bound of array or
				whether it is wanted to be placed in a place that is full.
				if it is valid and clear,print the player's char and skip to next person
				*/
				if (row >= ROW || row < 0 || column < 0 || 2 * column >= COLUMN){
					printf("Invalid coordinates.\nPlease enter again.\n");
				}
				else if (board[row][2 * column] == '_'){
					board[row][2 * column] = 'X';
					print_board(board);
					player++;
				}
				else{
					printf("The place where you enter the coordinates is full.\n");
					printf("Please enter again.\n");
				}
			}
			else {
				//it is similar to first if just players different
				printf("Player %d (O), enter your move (row,col): ", player);
				scanf("%d %d", &row, &column);
				if (row >= ROW || 2 * column >= COLUMN){
					printf("Invalid coordinates.\nPlease enter again.\n");
				}
				else if (board[row][2 * column] == '_'){
					board[row][2 * column] = 'O';
					print_board(board);
					player--;
				}
				else{
					printf("The place where you enter the coordinates is full.\n");
					printf("Please enter again.\n");	
				}
			}
			
			// check if there is a winner by using check_winner function
			draw_or_win = check_winner(board);	
		}
		
		/*
		if the draw_or_win variable is 'X'(from check_winner function)
		player 1 wins
		if it is 'O' player 2 wins
		if it is 1 
		that's mean board is full
		*/
		switch (draw_or_win){
			case 'X':
				printf("Player 1 (X) wins!\n");
				break;
			case 'O':
				printf("Player 2 (O) wins!\n");
				break;
			case 1:
				printf("It is draw!\n");
		}
		
		//ask the user if they  want to play again
		printf("Do you want to play again (Y/N default 'Y'): ");
		scanf(" %c", &play_again);
	}
	printf("Thanks for playing\n");
}

