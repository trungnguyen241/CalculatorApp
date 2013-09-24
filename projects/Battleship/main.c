/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 121, Fall 2011																	*	
* Programming Assignment 06: Battleship Game													*	
* Date: November 06, 2011																		*
* Description: This program will print out 2 board of size 10x10 and randomly place the ship to	* 
*				one board and program will ask user the option to randomly or manually place	*
*				his/her ship on board. The program will randomly choose who plays first in the	* 
*				game. Players turn to fire will be alternating. The program will update the		*
*				board to 'm' is that a miss or a '*' if that a hit. The game will end when all	* 
*				the ship of one player is destroyed. The program will also output all the		*
*				current move and indicate which ship is sunked and who is the winner to the file*
*************************************************************************************************/

#include "battleship.h"
int main (void)
{
	char user_board[ROW][COL];
	char computer_board[ROW][COL];
	char target_board[ROW][COL];
	int  target_row = 0, target_col = 0, hit_or_miss = 0, total_ship = 0;
	int turn = 0, option = 0, choose = 0;
	FILE *outfile = NULL;
	Stats user_stats = {0, 0, 0, 0.0}, computer_stats = {0, 0, 0, 0.0};
	srand((unsigned int) time (NULL));

	outfile = fopen("battleship.log", "w");
	do
	{	
		welcome_screen(&option, &choose);
		system("cls");

		switch (option)
		{
			case 1:
				game_rule();	
				break;
			case 2:
				//initialize the board
				ini_game_board(user_board, ROW, COL);
				ini_game_board(computer_board, ROW, COL);
				ini_game_board(target_board, ROW, COL);


				printf("COMPUTER BOARD\n");
				print_board(target_board, ROW, COL);
				randomly_place_ship(computer_board);
				print_board(computer_board, ROW, COL);

				printf("USER BOARD\n");
				//option for manually or randomly place ship
				if (choose == 1)
				{
					randomly_place_ship(user_board);
					print_board(user_board, ROW, COL);
				}
				else
				{
					manually_place_ships_on_board(user_board);
					print_board(user_board, ROW, COL);
				}

				select_who_starts_first(&turn);
				total_ship = 5;
				// game begin to play
				while(total_ship != 0)
				{
					if (turn == 1)
					{
						get_target(&target_row, &target_col);
						system("cls");
						hit_or_miss = check_shot(computer_board, target_row, target_col, turn);
						output_current_move(hit_or_miss, target_row, target_col, turn, outfile);
						update_board(hit_or_miss, target_board, target_row, target_col);
						printf("COMPUTER BOARD\n");
						print_board(target_board, ROW, COL);
						total_ship = check_if_sunk_ship(computer_board, outfile);
						player_stats(&user_stats, hit_or_miss);
						is_winner(user_stats, computer_stats, total_ship, turn, outfile);
						turn -= 1;		
					}
					
					if (turn == 0)
					{
						
						random_target(&target_row, &target_col);
						hit_or_miss = check_shot(user_board, target_row, target_col, turn);
						output_current_move(hit_or_miss, target_row, target_col, turn, outfile);
						update_board(hit_or_miss, user_board, target_row, target_col);
						printf("USER BOARD\n");			
						print_board(user_board, ROW, COL);
						total_ship = check_if_sunk_ship(user_board, outfile);
						player_stats(&computer_stats, hit_or_miss);
						is_winner(user_stats, computer_stats, total_ship, turn, outfile);
						turn += 1;
					}
				}
		}
	}while ((option == 1) || (option == 2));

	fclose(outfile);
	return (0);
}
