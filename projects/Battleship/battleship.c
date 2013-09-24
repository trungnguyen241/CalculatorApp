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

/*********************************************************************************************************
 * Function: welcome_screen ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function is used to display the option menu to the main screen and let the user 
 *				choose the options
 * Input parameters : None  
 * Output parameters: The pointer to option and choose type integer
 * Returns: none                                     
 * Preconditions: none                
 * Postconditions: The output of option and choose                      
 ***********************************************************************************************************/
void welcome_screen(int *option, int *choose)
{
	printf("\n******** WELCOME TO THE GAME OF BATTLESHIP ***********\n");
	printf("*1. Game Rule.                                       *\n");
	printf("*2. Play Game.                                       *\n");
	printf("*3. Exit Game.                                       *\n");
	printf("******************************************************\n");
	printf("--> ");
	scanf("%d", option);
	if (*option == 2)
	{
		printf("Please choose the option below: \n");
		printf("1. Randomly place ship on the board.\n");
		printf("2. Manually place ship on the board.\n");
		scanf("%d", choose);
	}
}

/*********************************************************************************************************
 * Function: game_rules ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function print out the instruction to user
 * Input parameters: none
 * Output parameters: none
 * Returns: none                                                             
 ***********************************************************************************************************/
void game_rule(void)
{
	printf("- Battle ship is a 2 player navy game.\n");
	printf("- The objective of the game is to sink all ships in your enemy's fleet.\n");
	printf("- The Player to sink his/her enemy's fleet first wins.\n"); 
	printf("- Both players' fleets consist of 5 ships.\n");
	printf("- the game will randomly choose who goes first in the game.\n");
	printf("- you will make a fire by entering the target row and column.\n");
	printf("- you can not fired at the same location twice.\n");
	printf("- the player win when they sunk all the enemy ship.\n");
	printf("- Good luck and have fun.\n");	
}

/*********************************************************************************************************
 * Function: ini_game_board ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function will initialize each cell of the array to the  character '-'
 * Input parameters : The 2 dimentional array board, number of row, and number of column  
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The 2 dimentional array board, number of row, and number of column has been read in             
 * Postconditions: none                     
 ***********************************************************************************************************/
void ini_game_board(char board[ROW][COL], int num_row, int num_col)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < num_row; row_index++)
		for (col_index = 0; col_index < num_col; col_index++)
			board[row_index][col_index] = '-';	
}

/*********************************************************************************************************
 * Function: print_board ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function will print out the 2 dimentional array board
 * Input parameters : The 2 dimentional array board, number of row, and number of column  
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The 2 dimentional array board, number of row, and number of column has been read in             
 * Postconditions: none                     
 ***********************************************************************************************************/
void print_board(char board[ROW][COL], int num_row, int num_col)
{
	int row_index = 0, col_index = 0;

	for (col_index = 0; col_index < ROW; ++ col_index)
		printf("%3d", col_index);
	for (row_index = 0; row_index < num_row; row_index++)
	{
		printf("\n%d",row_index);
		for (col_index = 0; col_index < num_col; col_index++)
			printf("%3c", board[row_index][col_index]);
		putchar ('\n');
	}	
}

/*********************************************************************************************************
 * Function: randomly_create_ship ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function randomly create the ship to the board
 * Input parameters : The 2 dimentional array board, length of the ship, and the initial letter of the ship  
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The 2 dimentional array board, length of the ship, and the initial letter of the ship
 *				  has been read in             
 * Postconditions: none                     
 ***********************************************************************************************************/
void randomly_create_ship(char board[ROW][COL], int ship_length, char ship_type)
{
	Boolean failure = TRUE;
	Dir direction = HORI;
	int row, col, i;
	while(failure)
	{
		row = rand() % ROW;
		if ((row + ship_length) > ROW)
		{
			direction = 0;
			col = rand() % (ROW - ship_length);
		}
		else
		{
			col = rand() % COL;
			if (col + ship_length > COL)
				direction = 1;
			else
				direction = (rand() % 2) == 0? 0 : 1;
		}
		failure = FALSE;

		for (i = 0; i < ship_length; i++)
		{
			if (direction == HORI && board[row][col + i] != '-')
				failure = TRUE;
			else if (direction == VERT && board[row + i][col] != '-')
				failure = TRUE;
		}
		if (!failure)
		{
			for (i = 0; i < ship_length; i++)
			{
				if (direction == 0)
					board[row][col + i] = ship_type;
				else
					board[row + i][col] = ship_type;
			}
		}
	}
}

/*********************************************************************************************************
 * Function: randomly_place_ship ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function randomly place the ship to the board
 * Input parameters : The 2 dimentional array board, length of the ship
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The 2 dimentional array board has been read in             
 * Postconditions: none                     
 ***********************************************************************************************************/
void randomly_place_ship(char board[ROW][COL])
{
		randomly_create_ship(board, CARRIER, 'c');
		randomly_create_ship(board, BATTLESHIP, 'b');
		randomly_create_ship(board, CRUISER, 'r');
		randomly_create_ship(board, SUBMARINE, 's');
		randomly_create_ship(board, DESTROYER, 'd');
}

/*********************************************************************************************************
 * Function: manually_get_ships_on_board ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function manually get the ship to the board based on the user input
 * Input parameters : The 2 dimentional array board, and the initial letter of the ship  
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The 2 dimentional array board, and the initial letter of the ship has been read in             
 * Postconditions: none                     
 ***********************************************************************************************************/
void manually_get_ships_on_board(char board[ROW][COL], char ship_type)
{
	int ship_length = 0, row = 0, col = 0, i = 0;
	Boolean failure = TRUE;
	Dir direction = HORI;

	while(failure)
	{
		switch(ship_type)
		{
			case 'c':
				printf("Please input cell to place the Carrier: ");
				ship_length = 5;
				break;
			case 'b':
				printf("Please input cell to place the Battleship: ");
				ship_length = 4;
				break;
			case 'r':
			case 's':
				if (ship_type == 'r')
					printf("Please input cell to place the Cruiser: ");
				else
					printf("Please input cell to place the Submarine: ");
				ship_length = 3;
				break;
			case 'd':
				printf("Please input cell to place the Destroyer: ");
				ship_length = 2;
				break;
		}
		failure = FALSE;

		scanf("%d %d", &row, &col);
		printf("Please choose direction ('0' for horizontal or '1' for vertical): ");
		scanf("%d", &direction);

		for (i = 0; i < ship_length; i++)
		{
			if ((direction == HORI  && board[row][col + i] != '-') || (col + ship_length > COL))
				failure = TRUE;
			else if (direction == VERT && board[row + i][col] != '-')
				failure = TRUE;
		}
		if (!failure)
		{
			for (i = 0; i < ship_length; i++)
			{
				if (direction == HORI)
					board[row][col + i] = ship_type;
				else
					board[row + i][col] = ship_type;
			}	
		}
		else
			printf("Invalid location. Please input location again\n");
	}
}

/*********************************************************************************************************
 * Function: manually_place_ships_on_board ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function manually place the ship to the board
 * Input parameters : The 2 dimentional array board
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The 2 dimentional array board has been read in             
 * Postconditions: none                     
 ***********************************************************************************************************/
void manually_place_ships_on_board(char board[ROW][COL])
{
	manually_get_ships_on_board(board, 'c');
	manually_get_ships_on_board(board, 'b');
	manually_get_ships_on_board(board, 'r');
	manually_get_ships_on_board(board, 's');
	manually_get_ships_on_board(board, 'd');
}

/*********************************************************************************************************
 * Function: select_who_starts_first ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function determine who will goes first in the game
 * Input parameters : none
 * Output parameters: The turn of the player
 * Returns: none                                     
 * Preconditions: none             
 * Postconditions: The player's turn is send out                     
 ***********************************************************************************************************/
void select_who_starts_first(int *turn)
{
	*turn = rand() % 2;
	if (*turn == 1)
		printf("The USER will goes first on this game\n");
	else
		printf("The COMPUTER will goes first on this game\n");
}

/*********************************************************************************************************
 * Function: get_target ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function get the target from user
 * Input parameters : none
 * Output parameters: The position of row and column of the board
 * Returns: none                                     
 * Preconditions: none             
 * Postconditions: The position of row and column of the board are send out                     
 ***********************************************************************************************************/
void get_target(int *target_row, int *target_col)
{
	printf("Enter the target coordinate to fire: ");
    scanf("%d %d", target_row, target_col);
}

/*********************************************************************************************************
 * Function: random_target ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function randomly create the target to fire
 * Input parameters : none
 * Output parameters: The position of row and column of the board
 * Returns: none                                     
 * Preconditions: none             
 * Postconditions: The position of row and column of the board are send out                     
 ***********************************************************************************************************/
void random_target(int *target_row, int *target_col)
{
	*target_row = rand() % 10;
	*target_col = rand() % 10;
}

/*********************************************************************************************************
 * Function: check_shot ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function check if the fired position is a hit or a miss
 * Input parameters : The 2 dimentional array board, the position of row and column, and the turn of player  
 * Output parameters: none
 * Returns: A '0' if it is a miss
 *			  '1' if it a hit
 * Preconditions: The 2 dimentional array board, the position of row and column, and the turn of player
 *				  has been read in             
 * Postconditions: A '0' if it is a miss
 *					 '1' if it a hit                   
 ***********************************************************************************************************/
int check_shot(char board[ROW][COL], int target_row, int target_col, int turn)
{
	int invalid = 1;
	while(invalid)
	{
		if (board[target_row][target_col] == '*' || board[target_row][target_col] == 'm')
		{
			printf("Invalid: you can not fired in the same spot twice\nPlease input target again\n");
			scanf("%d %d", &target_row, &target_col);
			invalid = 1;
		}
		else 
			invalid = 0;
	}
	if (board[target_row][target_col] == '-')
	{
		if (turn == 1)
			printf("User fired at [%d][%d]. It's a MISS\n\n", target_row, target_col );
		else
			printf("Computer fired at [%d][%d]. It's a MISS\n\n", target_row, target_col );
		return 0;
	}
	else
	{
		if (turn == 1)
			printf("User fired at [%d][%d]. It's a HIT\n\n", target_row, target_col );
		else
			printf("Computer fired at [%d][%d]. It's a HIT\n\n", target_row, target_col );		
		return 1;
	}
}

/*********************************************************************************************************
 * Function: update_board ()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function will update and print out the 2 dimentional array board
 * Input parameters : The value of hit or miss, 2 dimentional array board, number of row, and number of column  
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The value of hit or miss, 2 dimentional array board, number of row, and number of 
 *				    column has been read in             
 * Postconditions: none                     
 ***********************************************************************************************************/
void update_board(int hit_or_miss, char board[ROW][COL], int target_row, int target_col)
{
	if (hit_or_miss == 0)
		board [target_row][target_col] = 'm';
	else
		board [target_row][target_col] = '*';
}

/*********************************************************************************************************
 * Function: search_ship()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function search is a specific ship is stil on the board
 * Input parameters : The 2 dimentional array board, and the ship type 
 * Output parameters: none
 * Returns: A '0' if the specific ship is not found
			  '1' if the specific ship is found
 * Preconditions: The 2 dimentional array board, and the ship type been read in             
 * Postconditions: A '0' if the specific ship is not found
					 '1' if the specific ship is found                   
 ***********************************************************************************************************/
int search_ship(char board[ROW][COL], char ship_type)
{
	int row = 0, col = 0, status = 0;
	for (row = 0; row < ROW; row ++)
		for (col = 0; col < COL; col++)
			if (board[row][col] == ship_type)
				status = 1;
	return status;
}

/*********************************************************************************************************
 * Function: check_if_sunk_ship()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function check if a specific ship is sunked or not and output result to the file
 * Input parameters : The 2 dimentional array board
 * Output parameters:  The pointer to the file
 * Returns: The total of ship on board
 * Preconditions: The 2 dimentional array board has been read in             
 * Postconditions: The total of ship on board                
 ***********************************************************************************************************/
int check_if_sunk_ship(char board[ROW][COL], FILE *outfile)
{
	int carrier_ship = 0, battle_ship = 0, cruiser_ship = 0, submarine_ship = 0, destroyer_ship = 0;
	int total_ship = 0;
	carrier_ship += search_ship(board, 'c');
	if (carrier_ship == 0) {
		printf("The Carrier has sunked\n\n");
		fprintf(outfile, "The Carrier has sunked\n\n");
	}

	battle_ship += search_ship(board, 'b');
	if (battle_ship == 0) {
		printf("The BattleShip has sunked\n\n");
		fprintf(outfile, "The BattleShip has sunked\n\n");
	}

	cruiser_ship += search_ship(board, 'r');
	if (cruiser_ship == 0) {
		printf("The Cruiser has sunked\n\n");
		fprintf(outfile, "The Cruiser has sunked\n\n");
	}
	
	submarine_ship += search_ship(board, 's');
	if (submarine_ship == 0) {
		printf("The Submarine has sunked\n\n");
		fprintf(outfile, "The Submarine has sunked\n\n");
	}

	destroyer_ship += search_ship(board, 'd');
	if (destroyer_ship == 0) {
		printf("The Destroyer has sunked\n\n");
		fprintf(outfile, "The Destroyer has sunked\n\n");
	}

	total_ship = carrier_ship+ battle_ship + cruiser_ship + submarine_ship + destroyer_ship;
	return total_ship;
}

/*********************************************************************************************************
 * Function: output_player_stats()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function calculate and output the player statistic to the file
 * Input parameters : The struct of stats
 * Output parameters:  The pointer to the file
 * Returns: none
 * Preconditions: The struct of stats has been read in             
 * Postconditions: The output result to the file               
 ***********************************************************************************************************/
void output_player_stats(Stats stats, FILE *outfile)
{
	fprintf(outfile, "The total of hit      = %d\n", stats.num_hit);
	fprintf(outfile, "The total of miss     = %d\n", stats.num_miss);
	fprintf(outfile, "The total of shot     = %d\n", stats.total_shot);
	fprintf(outfile, "The percentage of hit = %lf\n\n", stats.hit_miss_ratio);
}

/*********************************************************************************************************
 * Function: is_winner()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function check if a winner is exits and print result to file
 * Input parameters : The 2 dimentional array board, the struct of user and computer statistic, the 
						total ship the turn of player
 * Output parameters:  The pointer to the file
 * Returns: none
 * Preconditions: The 2 dimentional array board, the struct of user and computer statistic, the 
				    total ship the turn of player has been read in             
 * Postconditions: The output to the file                
 ***********************************************************************************************************/
void is_winner(Stats user_stats, Stats computer_stats, int total_ship, int turn, FILE *outfile)
{
	switch(turn)
	{
		case 1:
			if (total_ship == 0)
			{
				printf("USER WIN!!!\n\nGAME OVER\n");
				fprintf(outfile, "USER WIN!!!\n\nGAME OVER\n\n");
				fprintf(outfile, "USER statistics table\n");
				output_player_stats(user_stats, outfile);
				fprintf(outfile, "COMPUTER statistics table\n");
				output_player_stats(computer_stats, outfile);
				exit();
			}
		break;
		case 0:
			if (total_ship == 0)
			{
				printf("COMPUTER WIN!!!\n\nGAME OVER\n");
				fprintf(outfile, "COMPUTER WIN!!!\n\nGAME OVER\n\n");
				fprintf(outfile, "USER statistics table\n");
				output_player_stats(user_stats, outfile);
				fprintf(outfile, "COMPUTER statistics table\n");
				output_player_stats(computer_stats, outfile);
				exit();
			}
			break;
	}
}
/*********************************************************************************************************
 * Function: player_stats()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function calculate the player statistic
 * Input parameters : The value indicate a miss or hit
 * Output parameters:  The pointer to struct stats
 * Returns: none
 * Preconditions: The The value indicate a miss or hit has been read in             
 * Postconditions: The struct of stats is sending out                
 ***********************************************************************************************************/
void player_stats(Stats *stats, int hit_or_miss)
{
	if (hit_or_miss == 1)
		(stats ->num_hit) ++;
	else
		(stats ->num_miss) ++;
	(stats ->total_shot = stats ->num_hit + stats ->num_miss);
	stats ->hit_miss_ratio = (double)stats ->num_hit / (double)stats ->total_shot *100;
}

/*********************************************************************************************************
 * Function: output_current_move()                                    
 * Date Created: November 06, 2011                          
 * Date Last Modified: November 06, 2011                      
 * Description: This function output the move made by player to the file
 * Input parameters : The value indicate a miss or hit, the number of row and column, and the turn
 * Output parameters:  The pointer to the file
 * Returns: none
 * Preconditions: The value indicate a miss or hit, the number of row and column, and the turn has been read in 
 * Postconditions: The result output to the file               
 ***********************************************************************************************************/
void output_current_move(int hit_or_miss, int target_row, int target_col, int turn, FILE *outfile)
{
	if (hit_or_miss == 0)
	{
		if (turn == 1)
			fprintf(outfile, "User fired at [%d][%d]. It's a MISS\n\n", target_row, target_col );
		else
			fprintf(outfile, "Computer fired at [%d][%d]. It's a MISS\n\n", target_row, target_col );
	}
	else
	{
		if (turn == 1)
			fprintf(outfile, "User fired at [%d][%d]. It's a HIT\n\n", target_row, target_col );
		else
			printf(outfile, "Computer fired at [%d][%d]. It's a HIT\n\n", target_row, target_col );		
	}

}


