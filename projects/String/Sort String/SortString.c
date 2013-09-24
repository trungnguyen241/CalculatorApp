/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 122, Spring 2012																	*	
* Programming Assignment 01: Sort String														*	
* Date: January 25, 2012																		*
* Description: This program read the string from a file, then it will sort the string in		*
*				ascending or descending order based on the user input. THe program then will	*
*				display out the result															*
*************************************************************************************************/

#include "SortString.h"

/*********************************************************************************************************
 * Function: sort_string_ascending ()                                    
 * Date Created: January 22, 2012                           
 * Date Last Modified: January 25, 2012                    
 * Description: This function is used to sort the string ino ascending order
 * Input parameters : The pointer to the fisrt characer in the string 
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The string have been read in
 * Postconditions: none         
 *********************************************************************************************************/

void sort_string_ascending(char *string)
{
	int len = 0, passes = 0, index = 0, temp = 0;

	len = strlen(string);

	for(passes = 0; passes < len; passes++)
		for(index = 0; index < len - 1; index++)
			if(string[index] > string[index + 1])
			{
				temp = string[index];
				string[index] = string[index + 1];
				string[index + 1] = temp;
			}
}

/*********************************************************************************************************
 * Function: sort_string_descending ()                                    
 * Date Created: January 22, 2012                           
 * Date Last Modified: January 25, 2012                    
 * Description: This function is used to sort the string ino descending order
 * Input parameters : The pointer to the fisrt characer in the string 
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The string have been read in
 * Postconditions: none         
 *********************************************************************************************************/

void sort_string_descending(char *string)
{
	int len = 0, passes = 0, index = 0, temp = 0;

	len = strlen(string);

	for(passes = 0; passes < len; passes++)
		for(index = 0; index < len - 1; index++)
			if(string[index] < string[index + 1])
			{
				temp = string[index];
				string[index] = string[index + 1];
				string[index + 1] = temp;
			}
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
	char str1[SIZE] = "sort this string in ascending order!";
	char str2[SIZE] = "sort this string in decending order!";

	printf("***********************Test Driver***********************************\n\n");
	printf("The test string is: %s\n", str1);
	sort_string_ascending(str1);
	printf("Sorted string ascending: %s\n", str1);
	printf("\nThe test string is: %s\n", str2);
	sort_string_descending(str2);
	printf("Sorted string descending: %s\n", str2);

	printf("**********************************************************************\n\n");
}