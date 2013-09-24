/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 121, Fall 2011																	*	
* Programming Assignment 8: Strings and Pointers												*	
* Date: Dec 07, 2011																			*
* Description: This program convert the english sentence to the pig Latin sentence				*
*************************************************************************************************/
#include "pigLatin.h"

int main(void)
{
	char string[MAX_SIZE];
	
	printf("Enter the phrase to translate: ");
	gets(string);

	printLatinWord(string);
	
	return 0;
}