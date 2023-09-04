#ifndef _UTIL_H_
#define _UTIL_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DOWN 'D'
#define RIGHT 'R'
#define UP 'U'
#define LEFT 'L'
#define SCORE_TXT "best_score.txt"
#define BEST_GAME_LOG "best_game.txt"
#define LAST_GAME_LOG "last_game.txt"


/*
struct that has 1 integer variable called as move and 1 integer 2d array calles as board
the name of the struct is puzzle 
I did this by using typedef 
*/

typedef struct{
	int board[3][5];
	int move;	
} puzzle;

// auxiliary functions
int f_strlen(const char *str);
void swap(int *a, int *b);
void find_index(const puzzle *p, int num, int *i_index, int *j_index);

//main functions
int get_inversion_count(int arr[9]);
int is_solvable(const puzzle *p);
int check_status(const puzzle *p);
int is_move_valid(puzzle *p, const char *str);
void initiliaze_struct_array(puzzle *p);
int shuffle_puzzle_board(int board[3][5]);
void print_board(const puzzle *p);

//File handling functions
void save_initial_status(const puzzle *p);
void save_status(const puzzle *p);
int is_new_bestscore(int point);
void new_best_score(int point);
void new_best_game(void);
void show_best_score(void);

//auto_finish function and its special functions
void fill_move(char move[4], char previous_move, const puzzle *p);
void make_computer_move(puzzle *p,char move[4]);
void auto_finish(puzzle *p, char previous_move);

#endif /* _UTIL_H_ */
