#include "util.h"

//I decided to make code as modular programming but Mehmet Burak said just fill function
//by not creating additional function. Thus I take function in comment line

/*void random_obstacle(BLOCK*** board){
	int row, col, o_value, i;
	srand(time(NULL));
	
	I decided to do that as a modular programming
	srand(time(NULL));
	the snake can be inputted ,so leave empty the top of the board
	and the left of the board 
	10 - 1 = 9 will generate number in interval 0,8
	by adding 1 it will return 1,9 number the left and top is empty
	
	do{
		row = rand() % (ROW - 1) + 1;
		col = rand() % (COLUMN -1) + 1;
	}while (board[row][col][0].type != 'e' && board[row][col][0].type != 'o');
	
	if (board[row][col][0].type == 'e') {
		//obstacle can have at least 1 block to 9 . Thus rand () % (MAX_HEIGHT -1) + 1
		o_value = rand() % (MAX_HEIGHT - 1) + 1;
	}
	else {
		
		blocks can be growth
		if MAX_HEIGHT -1- o_value == 0, the blocks has 9 nested block . This is limit
		if it is 5 , it will be rand() % 4 and it will return a value 0 to 3
		
		
		if (MAX_HEIGHT -1- o_value != 0)
			o_value += rand() % (MAX_HEIGHT - 1 - o_value);
	}
	
	free(board[row][col]);
		
	board[row][col] = (BLOCK *)malloc(o_value * sizeof(BLOCK));
	
	
	//adjusting the nested blocks of obstacles
	for (i = 0; i < o_value ; i++){
		board[row][col][i].type = 'o';
		board[row][col][i].value = o_value;
	}
}

void random_bait(BLOCK*** board){
	int row,col;
	
	do {
	row = rand() % (ROW - 1) + 1;
	col = rand() % (COLUMN -1) + 1;
	} while (board[row][col][0].type != 'e');
	
	board[row][col][0].type = 'b';
	board[bait_row][bait_col][0].value = 0;
}
*/

//init board function that create 3d pointer array
BLOCK*** init_board(void){
	int i, j, k, row, col, value;
	BLOCK *array, **matrix, ***board;
	
	/*
	The board consists of 10 rows and 10 columns,
	with the possibility of having nested blocks in each cell.
	*/
	//3d board with 10 row
	board = (BLOCK ***)malloc(ROW * sizeof(BLOCK **));
	
	for (i = 0; i < ROW; i++){
		//2d matrix that is the element of each row of board
		matrix = (BLOCK**)malloc(COLUMN * sizeof(BLOCK *));
		for (j = 0; j < COLUMN; j++){
			//1 d array is the element of each column of matrix
			//and the elemnts of the array is height of board
			array = (BLOCK *)malloc(sizeof(BLOCK));
			//taking addres of array to matrix
			matrix[j] = array;
			//*(matrix + j) = array;
		}
		//taking addres of matrix to board
		board[i] = matrix;
		//or *(board + i) = matrix;
	}
	
	//filling 'e' and 0 values with all cell of the board
	for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            board[i][j][0].type = 'e';
            board[i][j][0].value = 0;
        }
    }
	
	srand(time(NULL));
	/*
	the snake will be start 0.0
	so block and obstacle cannot be start from 0,0
	*/
	do {
		row = rand() % ROW;
		col = rand() % COLUMN;
	}while (row == 0 && col == 0);


	//obstacle can have at least 1 block to 9 . Thus rand () % (MAX_HEIGHT -1) + 1
	value = rand() % (MAX_HEIGHT - 1) + 1;
	free(board[row][col]);
	board[row][col] = (BLOCK *)malloc(value * sizeof(BLOCK));
	//row and col for block

	for (i = 0; i < value; i++){
		board[row][col][i].type = 'o';
		board[row][col][i].value = value;
	}
	//make sure the row and col is empty

	do {
		row = rand() % ROW;
		col = rand() % COLUMN;
		/*
		if the column is empty but row = 0 and col = 0 continue to loop
		(row == 0 && col == 0) it will give use 1 (0,0) continue 
		if the block is not empty (bait) it give us 1 continue to loop
		*/
	}while (board[row][col][0].type != 'e' || (row == 0 && col == 0));
	
	//putting type and value of bait
	board[row][col][0].type = 'b';
	board[row][col][0].value = 0;
	
	return (board);
}

//draw board funtion draw the board respect to snake
void draw_board(BLOCK*** board, Point * snake, int length_snake){
	int i, j, cond, snake_index, is_part;
	
	/* 
	the -1 is border of draw 
	0 to 9 is our game 
	COLUMN or ROW is border
	so
	
	this matrix is as a row
	
	-1-1-1-1-1-1-1-1-1-1-1-1
	0 0 0 0 0 0 0 0 0 0 0 0 
	1 1 1 1 1 1 1 1 1 1 1 1 
	2 2 2 2 2 2 2 2 2 2 2 2 
	3 3 3 3 3 3 3 3 3 3 3 3 
	4 4 4 4 4 4 4 4 4 4 4 4 
	5 5 5 5 5 5 5 5 5 5 5 5 
	6 6 6 6 6 6 6 6 6 6 6 6 
	7 7 7 7 7 7 7 7 7 7 7 7 
	8 8 8 8 8 8 8 8 8 8 8 8 
	9 9 9 9 9 9 9 9 9 9 9 9 
	101010101010101010101010
	Thus, -1 10 will be border
	0 to 9 will be the element of board
	
	
	
	ant tihs is matrix as a colum
	
	-1012345678910
	-1012345678910
	-1012345678910
	-1012345678910
	-1012345678910
	-1012345678910
	-1012345678910
	-1012345678910
	-1012345678910
	-1012345678910
	-1012345678910
	-1012345678910
	Thus, -1 10 will be border
	0 to 9 will be the element  of board
	
	*/
	for (i = -1; i < ROW + 1; i++){
		
		for(j = -1 ; j < COLUMN + 1; j++){
			//if indexes is border print border values
			if (i == -1 || i == ROW){
				printf("-");
			}
			else if (j == -1 || j == COLUMN){
				printf("|");
			}
			//if indexes of border equal to indexes of snake head print 'O' for head of snake
			else if (snake[0].row == i && snake[0].col == j) {
				printf("O");
			}
			else {
				//check the indexes is any body of the snake
				is_part = 0;
				for (snake_index = 1; snake_index < length_snake; snake_index++){
					if (snake[snake_index].row == i && snake[snake_index].col == j){
						is_part = 1;
						break;
					}
				}
				//if it is print 'X' for body
				if (is_part){
					printf("X");
				}
				//else check it is obstacle or bait if it is
				//print value of obstacle for obstacle
				else if (board[i][j][0].type == 'o'){
					printf("%d",board[i][j][0].value);
				}
				//if it is bait print '.' for bait
				else if (board[i][j][0].type == 'b'){
					printf(".");
				}
				//else it is empty print space character
				else {
					printf(" ");
				}
			}
		}
		//print new line for each 
		printf("\n");
	}	
}

//play function for playing game and it return nothing like it is said
void play(BLOCK *** board){
	/*
	n is lenght of snake 
	char u_move is user defined move
	*/
	int l_row, l_col, n;
	char u_move;
	/*
	The function initializes the snake with a length of 1 block at the top-left of the board.
	*/
	Point *snake = (Point *)malloc(sizeof(Point));
	snake[0].col = 0;
	snake[0].row = 0;
	n = 1;
	/*
	It asks
	the user for a new move until the game is over and draws the board using the draw_board() function
	before each move. After each move, the current state of the game is checked using the check_status()
	function. If the game is not over in the current state, then the board and snake are updated in the
	update() function.
	*/
	draw_board(board, snake, n);
	//take move
	printf("Please enter the next move of snake (w,s,d,a) : ");
	scanf(" %c",&u_move);
	//make move
	move(snake, n, u_move, &l_row, &l_col);
	//check whether the game is oover
	while (!check_status(board, snake, n)){
		//if the game is not over, update board and snake
		snake = update(board, snake, &n, l_row, l_col);
		//and make it loop
		draw_board(board, snake, n);
		printf("Please enter the next move of snake (w,s,d,a) : ");
		scanf(" %c",&u_move);
		move(snake, n, u_move, &l_row, &l_col);
	}

	//if game over, free memory board and snake and print game over
	printf("Game Over\n");

	//free
	int i,j;
	//freeing dimension of the board respectively
	for(i = 0;i < ROW;i++){
		for(j = 0;j < COLUMN; j++){
			free(board[i][j]);
		}
		free(board[i]);
	}
	free(board);
	free(snake);
		
}

/*
I decided to divided shifting to function
move and update
move will shift head and rest of body
after the last index will be updated in update function
I prevent to duplicate of code (70 line)
if you want to making shifting completely in update
use this version

void move(Point *snake, int  n, char u_move, int *l_row, int *l_col){
	int row,col;

	row = snake[0].row;
	col = snake[0].col;

	switch (u_move){
		case UP:
			if (n == 1)
				snake[0].row -= 1;
			else if (snake[0].row - 1 != snake[1].row){
				
				//up
				snake[0].row -= 1;
			}

			break;
		case DOWN:
			if (n == 1)
				snake[0].row += 1;
			else if (snake[0].row + 1 != snake[1].row){
				
				//down
				snake[0].
				row += 1;
			}

			break;
		
		case LEFT:
			if (n == 1)
				snake[0].col -= 1;
			else if (snake[0].col - 1 != snake[1].col){

				
				//down
				snake[0].col -= 1;
			}

			break;
			
		case RIGHT:
			if (n == 1)
				snake[0].col += 1;
			else if (snake[0].col + 1 != snake[1].col){
				
				//down
				snake[0].col += 1;
			}
			break;
	}

	if(row != snake[0].row || col != snake[0].col){
		*l_row = snake[0].row;
		*l_col = snake[0].col;
	}
}

Point* update(BLOCK*** board, Point *snake, int *n, int l_row, int l_col){
	static int move_counter = 0;
	static int obst_counter = 1;
	int i, row, col, is_part, temp_row, temp_col;
	Point *new_ptr;
	
	//shifting
	for (i = 1; i < *n; i++){
		temp_row = snake[i].row;
		temp_col = snake[i].col;
		snake[i].row = l_row;
		snake[i].col = l_col;
		l_row = temp_row;
		l_col = temp_col;
	}	

	new_ptr = snake;
	if (board[snake[0].row][snake[0].col][0].type == 'b'){
		//deleting the bait
		free(board[snake[0].row][snake[0].col]);
		board[snake[0].row][snake[0].col] = (BLOCK *)malloc(sizeof(BLOCK));
		board[snake[0].row][snake[0].col][0].type = 'e';
		board[snake[0].row][snake[0].col][0].value = 0;
		
		//changing the size of snake by 1
		new_ptr = (Point *)realloc(snake, sizeof(Point) * (*n + 1));

		new_ptr[*n].row = l_row;
		new_ptr[*n].col = l_col;
		(*n)++;
		
		//creating new bait on the board
		srand(time(NULL));
		
		do {
			row = rand() % ROW;
			col = rand() % COLUMN;
			is_part = 0;
			//if the random row and col is on the snake is_part = 1, find new number
			for (i = 0; i < *n; i++){
				if (snake[i].row == row && snake[i].col == col){
					is_part = 1;
					break;
				}
			}
			// 0 0 = 0
			// 0 1 = 1
			// 1 0 = 1
			// 1 1 = 1
		} while (board[row][col][0].type != 'e'  || is_part);
	
		board[row][col][0].type = 'b';
		board[row][col][0].value = 0;
	}
	else if (board[snake[0].row][snake[0].col][0].type == 'o'){
		//if there is obstacle thats mean the obstacle need to be destroyed;
		free(board[snake[0].row][snake[0].col]);
		board[snake[0].row][snake[0].col] = (BLOCK *)malloc(sizeof(BLOCK));
		board[snake[0].row][snake[0].col][0].type = 'e';
		board[snake[0].row][snake[0].col][0].value = 0;
		obst_counter -= 1;
	}
	
	move_counter += 1;
	if (move_counter % 5 == 0){
		int o_value;
		
		srand(time(NULL));
		if (obst_counter < 3){

			do{
				row = rand() % ROW ;
				col = rand() % COLUMN;
				//if the random row and col is on the snake is_part = 1, find new number
				is_part = 0;
				for (i = 0; i < *n; i++){
					if (snake[i].row == row && snake[i].col == col){
						is_part = 1;
						break;
					}
				}
				
			}while (board[row][col][0].type != 'e' || is_part);
			
			o_value = rand() % (MAX_HEIGHT - 1) + 1;
			obst_counter += 1;
		}
		else {
			do{
				row = rand() % ROW ;
				col = rand() % COLUMN;
				//if the random row and col is on the snake is_part = 1, find new number
				
			}while (board[row][col][0].type != 'o');
			o_value = board[row][col][0].value;
			o_value += rand() % (MAX_HEIGHT - o_value); 
		}

		free(board[row][col]);
		board[row][col] = (BLOCK *)malloc(o_value * sizeof(BLOCK));
		
		for (i = 0; i < o_value ; i++){
			board[row][col][i].type = 'o';
			board[row][col][i].value = o_value;
		}
	
	}
	return (new_ptr);
}

*/

/*
move function to make move
it takes  snake 
length of snake
move
last_row pointer to keep index of last move
last_col is same mission
it return nothing it is said
*/
void move(Point *snake,int  n,char u_move, int *l_row, int *l_col){
	int i, row, col, temp_row, temp_col;
	//it keeps indexes of snake in row and col
	row = snake[0].row;
	col = snake[0].col;
	//it make move respect to move
	switch (u_move){
		case UP:
		//if length of snake is 1 ,it don't need to shift body
			if (n == 1)
				snake[0].row -= 1;
		//else make sure the head of snake don't go on the body
			else if (snake[0].row - 1 != snake[1].row){

				for (i = 1; i < n; i++){
					temp_row = snake[i].row;
					temp_col = snake[i].col;
					snake[i].row = row;
					snake[i].col = col;
					row = temp_row;
					col = temp_col;
				}
				
				//up
				snake[0].row -= 1;
			}
			break;
		//same logic is valid for other move
		case DOWN:
			if (n == 1)
				snake[0].row += 1;
			else if (snake[0].row + 1 != snake[1].row){

				for (i = 1; i < n; i++){
					temp_row = snake[i].row;
					temp_col = snake[i].col;
					snake[i].row = row;
					snake[i].col = col;
					row = temp_row;
					col = temp_col;
				}
				
				//down
				snake[0].row += 1;
			}
			break;
		
		case LEFT:
			if (n == 1)
				snake[0].col -= 1;
			else if (snake[0].col - 1 != snake[1].col){

				for (i = 1; i < n; i++){
					temp_row = snake[i].row;
					temp_col = snake[i].col;
					snake[i].row = row;
					snake[i].col = col;
					row = temp_row;
					col = temp_col;
				}
				
				//down
				snake[0].col -= 1;
			}
			break;
			
		case RIGHT:
			if (n == 1)
				snake[0].col += 1;
			else if (snake[0].col + 1 != snake[1].col){
				for (i = 1; i < n; i++){
					temp_row = snake[i].row;
					temp_col = snake[i].col;
					snake[i].row = row;
					snake[i].col = col;
					row = temp_row;
					col = temp_col;
				}
				
				//down
				snake[0].col += 1;
			}
			break;
	}
	//save the last indexes of the snake
	*l_row = row;
	*l_col = col;
}

int check_status(BLOCK*** board, Point *snake, int  n){
	int i, res;
	
	/*
	1. Does the head of the snake hit its own body?
	if the head of the snake is same with any other part of the snake
	it mean's the game is over (head collide with its body
	*/
	for (i = 1; i < n; i++){
		if (snake[0].row == snake[i].row && snake[0].col == snake[i].col){
			printf("The head of the snake hit its own body\n");
			return (1);
		}
	}
	
	/*
	Does the snake collide with the wall?
	if row or col is -1 or 10 ,the game is over (collide with the wall 
	*/
	if (snake[0].row == 10 || snake[0].row == -1 || snake[0].col == -1 || snake[0].col == 10){
		printf("The head of the snake collide with the wall\n");
		return (1);
	}
	/*
	Does the snake encounter an obstacle that has x number of blocks, where x is greater than the
	length of the snake?
	*/
	if(board[snake[0].row][snake[0].col][0].type == 'o'){
		if(board[snake[0].row][snake[0].col][0].value > n){
			printf("The snake encounter an obstacle taller than itself\n");
			return (1);	
		}
	}
	
	return (0);
}

Point* update(BLOCK*** board, Point *snake, int *n, int l_row, int l_col){
	/*
	move_counter will count the move
	obst_counter will count the obstacle that is on the board
	i is element of loop 
	row col is element of indexing board
	is_part check the body
	new_ptr will be used realloc the snake
	it will return*/
	static int move_counter = 0;
	static int obst_counter = 1;
	int i, row, col, is_part;
	Point *new_ptr;
	
	new_ptr = snake;
	/*
	if the block that snake encountered is bait
	delete the bait
	increase the length of snake by 1
	shift it
	create an bait random
	 */
	if (board[snake[0].row][snake[0].col][0].type == 'b'){
		//deleting the bait
		free(board[snake[0].row][snake[0].col]);
		board[snake[0].row][snake[0].col] = (BLOCK *)malloc(sizeof(BLOCK));
		board[snake[0].row][snake[0].col][0].type = 'e';
		board[snake[0].row][snake[0].col][0].value = 0;
		
		//changing the size of snake by 1
		new_ptr = (Point *)realloc(snake, sizeof(Point) * (*n + 1));
		new_ptr[*n].row = l_row;
		new_ptr[*n].col = l_col;
		(*n)++;
		
		//creating new bait on the board
		srand(time(NULL));
		
		do {
			row = rand() % ROW;
			col = rand() % COLUMN;
			is_part = 0;
			//if the random row and col is on the snake is_part = 1, find new number
			for (i = 0; i < *n; i++){
				if (snake[i].row == row && snake[i].col == col){
					is_part = 1;
					break;
				}
			}
			// 0 0 = 0
			// 0 1 = 1
			// 1 0 = 1
			// 1 1 = 1
		} while (board[row][col][0].type != 'e'  || is_part);
	
		board[row][col][0].type = 'b';
		board[row][col][0].value = 0;
	}
	/*
	if the head of snake encountered with an obstacle
	and the game didn't end up
	destroy the obstacle
	and decrease obst_counter by 1*/
	else if (board[snake[0].row][snake[0].col][0].type == 'o'){
		//if there is obstacle thats mean the obstacle need to be destroyed;
		free(board[snake[0].row][snake[0].col]);
		board[snake[0].row][snake[0].col] = (BLOCK *)malloc(sizeof(BLOCK));
		board[snake[0].row][snake[0].col][0].type = 'e';
		board[snake[0].row][snake[0].col][0].value = 0;
		obst_counter -= 1;
	}
	/*
	increase move counter by one for every shifting and move
	*/
	move_counter += 1;
	/*
	add new obstacle or increase the height of obstacle for each 5 move
	*/
	if (move_counter % 5 == 0){
		int o_value;
		
		srand(time(NULL));
		/*
		if there are not 3 obstacle in board create an obstacle
		*/
		if (obst_counter < 3){

			do{
				row = rand() % ROW ;
				col = rand() % COLUMN;
				//if the random row and col is on the snake is_part = 1, find new number
				is_part = 0;
				for (i = 0; i < *n; i++){
					if (snake[i].row == row && snake[i].col == col){
						is_part = 1;
						break;
					}
				}
				
			}while (board[row][col][0].type != 'e' || is_part);
			
			o_value = rand() % (MAX_HEIGHT - 1) + 1;
			obst_counter += 1;
		}
		/*
		else change the height of the obsstacle randomly
		*/
		else {
			do{
				row = rand() % ROW ;
				col = rand() % COLUMN;
				//if the random row and col is on the snake is_part = 1, find new number
				
			}while (board[row][col][0].type != 'o');
			o_value = board[row][col][0].value;
			o_value += rand() % (MAX_HEIGHT - o_value); 
		}
		/*
		free the obstacle 
		and create new one
		I didn't use realloc because 
		I will not copy anything from old one
		so it is better to malloc new and free old one
		and put it type and value new value*/
		free(board[row][col]);
		board[row][col] = (BLOCK *)malloc(o_value * sizeof(BLOCK));
		
		for (i = 0; i < o_value ; i++){
			board[row][col][i].type = 'o';
			board[row][col][i].value = o_value;
		}
	
	}
	/*
	return new_ptr(snake)*/
	return (new_ptr);
}
