#include "util.h"

int main(){
	int choice, i, j, s, point;
	char str[5];
	
	// the puzzle game
	puzzle game;
	do {
		// menu
		printf("\nWelcome to the 8-Puzzle Game!\n");
		printf("Please Select an option:\n");
		printf("1. Play game as a user\n");
		printf("2. Finish the game with PC\n");
		printf("3. Show the best score\n");
		printf("4. Exit\n");
		printf("choice :");
		scanf("%d",&choice);
		printf("\n");
		//arranging the random seed by time
		srand(time(NULL));
		
		//initiliziating the array
		initiliaze_struct_array(&game);
		do {
			//making sure the board is shuffled
			for(s = 0; s < 9; s++){
				shuffle_puzzle_board(game.board);
			}
		}while (!is_solvable(&game));
		
		game.move = 0;
		switch (choice){
			
			case 1:
				//saving initial status to txt
				save_initial_status(&game);
				//playing game
				while (check_status(&game) && game.move <= 100){
					print_board(&game);
					printf("Enter your move (number-direction, e.g, 2-R): ");
					scanf("%s",str);
					//checking the more is valid if it is not valid
					if (!is_move_valid(&game, str)){
						printf("the move you entered is invalid! Try again.\n");
					}
					else {
						game.move++;
						save_status(&game);
					}
				}
				//max point = 1000 and it will be decreased by every move
				point = 1000 - game.move*10;
				//if point is great than 0 user win the game else score will be 0
				if (point >= 0){
					printf("\n\nCongratulations, You won!\n\n");
					printf("Total number of moves: %d\n",game.move);
					printf("Your score: %d\n",point);
					if (is_new_bestscore(point)){
						new_best_score(point);
						new_best_game();
						printf("and this is new record !!!\n\n");
					}
				}
				else {
					printf("Your score is 0\n");
					printf("You couldn't complete puzzle in 100 move\n");
				}
				break;
			case 2:
			//save initial status
				save_initial_status(&game);
				print_board(&game);
				//and auto play
				auto_finish(&game, 'R');
				break;
			case 3:
			//show best score by reading best_score.txt
				show_best_score();
				break;
			case 4:
				printf("Thanks for playing .");
				break;
			default :
				printf("Invalid input");
		}
	} while (choice != 4);
	
	return (0);
}

