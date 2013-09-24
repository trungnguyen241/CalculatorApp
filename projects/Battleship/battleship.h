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
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <stdio.h>
#define ROW 10
#define COL 10
#define CARRIER 5
#define BATTLESHIP 4
#define CRUISER 3
#define SUBMARINE 3
#define DESTROYER 2

//define new type enum and struct

typedef enum
{
	FALSE, TRUE
}Boolean;

typedef enum
{
	HORI, VERT
}Dir;

typedef struct stats
{
	int num_hit;
	int num_miss;
	int total_shot;
	double hit_miss_ratio;
}Stats;

/* List the function prototypes for the program 
   The descriptions for each of the functions can be seen in a comment block
   above each function definition */

void welcome_screen(int *option, int *choose);
void game_rule(void);
void ini_game_board(char board[ROW][COL], int num_row, int num_col);
void print_board(char board[ROW][COL], int num_row, int num_col);
void randomly_create_ship(char board[ROW][COL], int ship_length, char ship_type);
void randomly_place_ship(char board[ROW][COL]);
void manually_get_ships_on_board(char board[ROW][COL], char ship_type);
void manually_place_ships_on_board(char board[ROW][COL]);
void select_who_starts_first(int *turn);
void get_target(int *target_row, int *target_col);
void random_target(int *target_row, int *target_col);
int check_shot(char board[ROW][COL], int target_row, int target_col, int turn);
void update_board(int hit_or_miss, char board[ROW][COL], int target_row, int target_col);
int search_ship(char board[ROW][COL], char ship_type);
int check_if_sunk_ship(char board[ROW][COL], FILE *outfile);
void output_current_move(int hit_or_miss, int target_row, int target_col, int turn, FILE *outfile);
void is_winner(Stats user_stats, Stats computer_stats, int total_ship, int turn, FILE *outfile);
void player_stats(Stats *stats, int hit_or_miss);
void output_player_stats(Stats stats, FILE *outfile);

#endif