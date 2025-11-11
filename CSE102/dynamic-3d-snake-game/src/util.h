#ifndef _UTIL_H_
#define _UTIL_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'
#define ROW 10
#define COLUMN 10
#define MAX_HEIGHT 10

typedef struct point {
	int row;
	int col;
} Point;

typedef struct block{
	char type;
	int value;
	
} BLOCK;

/*void random_obstacle(BLOCK*** board);
void random_bait(BLOCK*** board);
*/
BLOCK*** init_board(void);
void draw_board(BLOCK*** board, Point * snake, int length_snake);
void play(BLOCK *** board);
void move(Point *snake, int  n, char u_move, int *l_row, int *l_col);
int check_status(BLOCK*** board, Point *snake, int  n);
Point* update(BLOCK*** board, Point *snake, int *n, int l_row, int l_col);


#endif /* _UTIL_H_ */
