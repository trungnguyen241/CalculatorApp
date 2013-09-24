/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 122, Spring 2012																	*	
* Programming Assignment 01: Palindrome															*	
* Date: January 25, 2012																		*
* Description: This program read the string from a file, determine whether the string is a		*
*				palindrome or not, and display the result to the screen							*
*************************************************************************************************/

#include "Palindrome.h"

int main(void)
{
	FILE *inp = NULL;
	char string[SIZE], new_string[SIZE];
	int i = 0;
	inp = fopen ("inp.txt", "r");

	display_test_driver();

	fgets(string, SIZE, inp);
	printf("The current string is: %s\n\n", string);

	remove_punct_and_make_lower_case(string);
	printf("String with no punctuation: %s\n", string);

	strcpy(new_string, string);

	reverse_string(new_string);
	printf("Reverse string with no punctuation: %s\n\n", new_string);

	determine_palindrome(string, new_string);
	
	fclose(inp);
	return 0;
}
