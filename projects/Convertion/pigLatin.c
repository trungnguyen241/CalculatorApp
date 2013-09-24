/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 121, Fall 2011																	*	
* Programming Assignment 8: Strings and Pointers												*	
* Date: Dec 07, 2011																			*
* Description: This program convert the english sentence to the pig Latin sentence				*
*************************************************************************************************/

#include "pigLatin.h"

/*********************************************************************************************************
 * Function: printLatinWord ()                                    
 * Date Created: Dec 07, 2011                          
 * Date Last Modified: Dec 07, 2011                      
 * Description: This function print out the translate sentence to pig Latin
 * Input parameters: char string[]
 * Preconditions: The string has been read in             
 * Postconditions: none                                                           
 ***********************************************************************************************************/
void printLatinWord(char string[])
{
	char *token;

	printf("The sentence in Pig Latin is: ");
	token = strtok(string, " ");

	while (token != NULL)
	{
		printf("%s%c%s", token + 1, token[0], "ay ");
		token = strtok(NULL, " ");
		printf(" ");
	}
	printf("\n");
}