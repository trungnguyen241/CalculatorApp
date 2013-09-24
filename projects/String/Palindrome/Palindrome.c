/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 122, Spring 2012																	*	
* Programming Assignment 01: Palindrome															*	
* Date: January 25, 2012																		*
* Description: This program read the string from a file, determine whether the string is a		*
*				palindrome or not, and display the result to the screen							*
*************************************************************************************************/

#include "Palindrome.h"

/*********************************************************************************************************
 * Function: reverse_string ()                                    
 * Date Created: January 22, 2012                           
 * Date Last Modified: January 22, 2012                    
 * Description: This function is used to reverse the string by each character
 * Input parameters : The pointer to the fisrt characer in the string 
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The string have been read in
 * Postconditions: none         
 *********************************************************************************************************/

void reverse_string(char *string)
{
	int first = 0, last = 0, length = 0;
	char temp ;

	length = strlen(string);
	for (first = 0, last = length - 1; first <= last; first++, last--)
	{
		temp = string[first];
		string[first] = string[last];
		string[last] = temp;	
	}	
}

/*********************************************************************************************************
 * Function: remove_punct_and_make_lower_case ()                                    
 * Date Created: January 22, 2012                           
 * Date Last Modified: January 22, 2012                    
 * Description: This function is used to remove all the space and punctuation in the string
 * Input parameters : The pointer to the fisrt characer in the string 
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The string have been read in
 * Postconditions: none         
 *********************************************************************************************************/

void remove_punct_and_make_lower_case(char *ch)
{
	char *src = ch, *dest = ch;

	while(*src)
	{
		if (ispunct(*src) || isspace(*src))
			src++;
		else if (isupper(*src))
		{
			*dest++ = tolower(*src);
			src++;
		}
		else if (src == dest)
		{
			src++;
			dest++;
		}
		else
			*dest++ = *src++;
	}
	*dest = 0;
}

/*********************************************************************************************************
 * Function: determine_palindrome ()                                    
 * Date Created: January 22, 2012                          
 * Date Last Modified: January 22, 2012                    
 * Description: This function determine whether the string is a palindrome or not
 * Input parameters : The pointer to the fisrt characer in the string and new string
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The string and new string has been read in
 * Postconditions: none                     
 ***********************************************************************************************************/
void determine_palindrome(char *string, char *new_string)
{
	if (strcmp(new_string, string) == 0)
		printf("The string is palindrome\n\n");
	else
		printf("The string is NOT palindrome\n\n");
}
/*********************************************************************************************************
 * Function: display_test_driver ()                                    
 * Date Created: January 22, 2012                          
 * Date Last Modified: January 22, 2012                    
 * Description: This function display the test driver to the screen
 * Input parameters : none
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: none
 * Postconditions: none                     
 ***********************************************************************************************************/

void display_test_driver(void)
{
	char str1[SIZE] = "car, rac?!";
	char str2[SIZE];

	printf("***********************Test Driver*************************\n\n");
	printf("The test string is: %s\n\n", str1);

	remove_punct_and_make_lower_case(str1);
	printf("String with no punctuation: %s\n", str1);

	strcpy(str2, str1);

	reverse_string(str2);
	printf("Reverse string with no punctuation: %s\n\n", str2);

	determine_palindrome(str1, str2);


	printf("************************************************************\n\n");
}
