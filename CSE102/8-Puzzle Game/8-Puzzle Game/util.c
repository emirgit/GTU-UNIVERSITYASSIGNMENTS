#include "util.h"

//basically strlen function 
int f_strlen(const char *str){
	int i;
	
	i = 0;
	while (str[i] != '\0'){
		i++;
	}
	
	return (i);
}

/*
this function finds the index of the given number in puzzle
it will return i index and j index of board
*/
void find_index(const puzzle *p, int num, int *i_index, int *j_index){
	int i, j;
	
	for (i = 0; i < 3; i++){
		for(j = 0; j < 5; j++){
			if (p->board[i][j] == num){
				*i_index = i;
				*j_index = j;
				return;
			}
		}
	}
}

//basically swap function
void swap(int *a, int *b){
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

/*
check_status function takes an pointer that point the struct of the game
i and j are elements of the 2d array(board) in puzzle struct
The winning condition of the game is as follows :
1 2 3
4 5 6
7 8 _

count starts from 1 and checks all the cell of the array
p->board[0][0] = 1
p->board[0][2] = 2
p->board[0][4] = 3
...
p->board[2][2] = 8
it will increment count by 1 each time
it will continue until count is 9 to prevent not checking the p->board[2][4]
Because if all other cells are like above,the last cell will be '_' character

if the game is end return 0
else return 1
*/

/*
this algorith is taken by https://www.geeksforgeeks.org/check-instance-8-puzzle-solvable/"

What is inversion? 
A pair of tiles form an inversion if the values on tiles are in reverse order of their appearance in goal state. 
For example, the following instance of 8 puzzle has two inversions, (8, 6) and (8, 7). 

It is not possible to solve an instance of 8 puzzle if number of inversions is odd in the input state. 
*/
int get_inversion_count(int arr[9]){
	int inv_counter, i, j;
	
	inv_counter = 0;
	
	for(i = 0; i < 9; i++){
		for(j = i + 1; j < 9; j++){
			if (arr[j] != '_' && arr[i] != '_' && arr[i] > arr[j])
				inv_counter++;
		}
	}
	
	return (inv_counter);
}

/*
if the result of is_solvable is 1 it is solvable
else is not solvable
*/

int is_solvable(const puzzle *p){
	int i, j,inv_count;
	int arr[9];
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 5 ; j += 2){
			arr[(i * 3) + (j / 2)] = p->board[i][j];
			
		}
	}
	inv_count = get_inversion_count(arr);
	return (inv_count % 2 == 0);
}
/*
check_status will check the game is end or not
if the status is as follow it will return 1 else 0:
1 2 3
4 5 6
7 8 _
*/
int check_status(const puzzle *p){
	int i, j, count;
	
	count = 1;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 5 && count != 9; j += 2){
			if (p->board[i][j] != count)
				return (1);
			count++;
		}
	}

	return (0);
}

/*
if the move is valid return 1 
else 0
*/
int is_move_valid(puzzle *p, const char *str){
	int i, j, res;
	
	res = 1;
	// if length of move is different from 3 ,move is invalid
	if (f_strlen(str) != 3)
		res = 0;
	//if number is not (1,2,3,4,5,6,7,8),the nmove is invalid
	else if(!(str[0] >= '1' && str[0] <= '8'))
		res = 0;
	//if there isn't a dash,the move is invalid
	else if(str[1] != '-')
		res = 0;
	//if the directin is not valid according to number ,the move is invalid
	//or if it is in border
	else {
		switch (str[2]){
			case DOWN:
				find_index(p, str[0] - 48, &i, &j);
				if (i == 2)
					res = 0;
				else if (p->board[i + 1][j] != 95)
					res = 0;
				else {
					swap(&(p->board[i][j]), &(p->board[i + 1][j]));
				}
				break;
			case UP:
				find_index(p, str[0] - 48, &i, &j);
				if (i == 0)
					res = 0;
				else if (p->board[i - 1][j] != 95)
					res = 0;
				else {
					swap(&(p->board[i][j]), &(p->board[i - 1][j]));
				}				
				break;
			case RIGHT:
				find_index(p, str[0] - 48, &i, &j);
				if (j == 4)
					res = 0;
				else if (p->board[i][j + 2] != 95)
					res = 0;
				else {
					swap(&(p->board[i][j]), &(p->board[i][j + 2]));
				}					
				break;
			case LEFT:
				find_index(p, str[0] - 48, &i, &j);
				if (j == 0)
					res = 0;
				else if (p->board[i][j - 2] != 95)
					res = 0;
				else {
					swap(&(p->board[i][j]), &(p->board[i][j - 2]));
				}	
				break;
			default :
				res = 0;
		}
	}
	
	return (res);
}

/*
it will intiliaze the array of the game as follow:

1 2 3
4 5 6
7 _ 8

and it will shuffle in shuffle function.
*/

void initiliaze_struct_array(puzzle *p){
	int i, j, counter;
	counter = 1;
	for (i = 0; i < 3; i++){
		for(j = 0; j < 5; j++){
			if (j % 2 != 1){
				if (counter == 8){
					p->board[i][j] = '_';
					p->board[i][j + 2] = 8;
					break;
				}
				p->board[i][j] = counter;
				counter++;
			}
			else
				p->board[i][j] = 0;
		}
	}
}

/*
shuffling puzzle board by taking random number
ı'm taking random index and ı change value of spesific index respectively
*/
int shuffle_puzzle_board(int board[3][5]){
	int i, j, randomcol, randomrow;
	

	for (i = 2; i > 0; i--){
		for (j = 4; j > 0; j -= 2){
			
			if (!(i == 2 && j == 2)){
				do {
				randomcol = 2 * (rand() % ((j + 1) / 2));
				randomrow = rand() % (i + 1);
				} while (randomcol == 2 && randomrow == 2);
				swap(&board[i][j], &board[randomrow][randomcol]);
			}
		}
	}
}

/*
print board function
*/
void print_board(const puzzle *p){
	int i,j;
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 5 ; j++){
			if (p->board[i][j] != 0){
				if (p->board[i][j] != 95)
					printf("%d",p->board[i][j]);
				else
					printf("%c",p->board[i][j]);
			}
			else
				printf(" ");
		}
		printf("\n");
	}	
}
/*
saving initial status
I open file with write mode because of ı need to delete old data
and it print datas to file respectively
*/
void save_initial_status(const puzzle *p){
	FILE *fp;
	int i,j;
	
	fp = fopen(LAST_GAME_LOG, "w");
	
	fputs("Initial state of the board :\n",fp);
	for (i = 0; i < 3; i++){
		for (j = 0; j < 5 ; j++){
			if (p->board[i][j] != 0){
				if (p->board[i][j] != 95)
					fputc(p->board[i][j] + 48,fp);
				else
					fputc('_',fp);
			}
			else
				fputc(' ',fp);
		}
		fputc('\n',fp);
	}
	
	fclose(fp);	
}
/*
save status is similar to save initial status
but the difference is ı opened file with append mode
the filepointer start from end of the file
instead of all over*/
void save_status(const puzzle *p){
	FILE *fp;
	int i,j;
	
	fp = fopen(LAST_GAME_LOG, "a");
	
	fprintf(fp,"Move %d \n",p->move);
	for (i = 0; i < 3; i++){
		for (j = 0; j < 5 ; j++){
			if (p->board[i][j] != 0){
				if (p->board[i][j] != 95)
					fputc(p->board[i][j] + 48,fp);
				else
					fputc('_',fp);
			}
			else
				fputc(' ',fp);
		}
		fputc('\n',fp);
	}
	
	fclose(fp);
}

/*
return 1 if it is best score
else return 0
*/
int is_new_bestscore(int point){
	FILE *fp;
	//char ch;
	int best_score;
	
	fp = fopen(SCORE_TXT, "r");
	
	/*do{
		ch = fgetc(fp);
		if (ch == ':')
			break;
	} while(feof(fp));
	fgetc(fp);
	*/
	fscanf(fp, "%d", &best_score);
	
	fclose(fp);
	return (best_score < point);
}
/*
printing new best score
*/
void new_best_score(int point){
	FILE *fp;
	
	fp = fopen(SCORE_TXT, "w");
	fprintf(fp,"%d",point);
	
	fclose(fp);
}
/*
printing best game if the user want to see
this is extra feature that ı want to make code pretty
*/
void new_best_game(void){
	FILE *fpread, *fpwrite;
	char ch;
	
	fpread = fopen(LAST_GAME_LOG, "r");
	fpwrite = fopen(BEST_GAME_LOG, "w");
	
	ch = fgetc(fpread);
	while(!feof(fpread)){
		fputc(ch, fpwrite);
		ch = fgetc(fpread);
	};
	
	fclose(fpread);
	fclose(fpwrite);
}
/*
showing best score to user (the third option)
*/
void show_best_score(void){
	FILE *fp;
	int best_score;
	
	fp = fopen(SCORE_TXT, "r");
	
	fscanf(fp, "%d", &best_score);
	
	printf("Best score is : %d\n",best_score);
	
	fclose(fp);
}
/*
filling move for computer
*/
void fill_move(char move[3], char previous_move, const puzzle *p){
	int direction, i, j, int_pre_move, flag; 
	move[1] = '-';
	
	/*
	0 = DOWN
	1 = LEFT
	2 = RIGHT
	3 = UP
	if previous_move of number is down that's mean underscore went up
	underscore can not go down
	so int_pre_move = 3 if previous move 'D'
	
	*/
	switch(previous_move){
		case 'D':
			int_pre_move = 0;
			break;
		case 'L':
			int_pre_move = 1;
			break;
		case 'R':
			int_pre_move = 2;
			break;
		case 'U':
			int_pre_move= 3;
			break;
	}
	/*
	taking random values 
	be sure direction is not same as previous move
	*/
	do{
		flag = 0;
		direction = (rand() % 4);
		if (direction == int_pre_move){
			flag = 1;
			continue;
		}
			
		find_index(p, 95, &i, &j);
		switch (direction){
			case 0:
				if (i == 2)
					flag = 1;
				break;
			case 1:
				if (j == 0)
					flag = 1;
				break;
			case 2:
				if (j == 4)
					flag = 1;
				break;
			case 3:
				if (i == 0)
					flag = 1;
		}
		//j = 0 and move = left
	} while(flag);
	/*
	I determine the direction by underscore
	but the move will be made by number
	so if it is Down ,the number will go up
	if it is right , the number will go left
	*/
	switch (direction){
		case 0:
			move[0] = p->board[i + 1][j] + 48;
			move[2] = 'U';
			break;
		case 1:
			move[0] = p->board[i][j - 2] + 48;
			move[2] = 'R';
			break;
		case 2:
			move[0] = p->board[i][j + 2] + 48;
			move[2] = 'L';
			break;
		case 3:
			move[0] = p->board[i - 1][j] + 48;
			move[2] = 'D';
			break;
	}
	move[3] = '\0';
}
/*
make computer move directly by direction
computer don't need to check it because
the move correct because computer dit it
*/
void make_computer_move(puzzle *p,char move[4]){
	int i,j;

	find_index(p, move[0] - 48, &i, &j);
	switch (move[2]){
		case DOWN:
			swap(&(p->board[i][j]), &(p->board[i + 1][j]));
			break;
		case UP:
			swap(&(p->board[i][j]), &(p->board[i - 1][j]));			
			break;
		case RIGHT:
			swap(&(p->board[i][j]), &(p->board[i][j + 2]));				
			break;
		case LEFT:
			swap(&(p->board[i][j]), &(p->board[i][j - 2]));
			break;
	}
}
/*
recursive auto_finish function
it takes 2 parameter called as puzzle pointer and previous move
it fill move array
and it will move until the result condition will be provided
*/
void auto_finish(puzzle *p, char previous_move){
	if (!check_status(p)) {
		printf("\nComputer finished the game.\n");
        printf("Total number of computer moves: %d\n", p->move);
        return;
    }
    char move[4];
    
    fill_move(move,previous_move, p);
	/*
	0 = DOWN
	1 = LEFT
	2 = RIGHT
	3 = UP
	*/
	make_computer_move(p, move);
	p->move += 1;
	printf("Computer Move : %s\n\n",move);
	print_board(p);
	save_status(p);
	
	auto_finish(p, move[2]);
}
