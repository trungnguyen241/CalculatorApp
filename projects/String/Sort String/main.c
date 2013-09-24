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

int main(void)
{	
	int choice = 0, i = 1;
	char string[SIZE];

	FILE *inp = NULL;

	inp = fopen("inp.txt", "r");

	display_test_driver();

	printf("Please enter the option:\n1.Sort Ascending String\n2.Sort Descending String\n--->");
	scanf("%d", &choice);

	if (choice == 1)
	{
		while(!feof(inp))
		{
			fgets(string, SIZE, inp);
	
			sort_string_ascending(string);
			printf("Sorted the %d string ascending: %s\n", i, string);
			i ++;
		}
	}
	else if (choice == 2)
	{
		while(!feof(inp))
		{
			fgets(string, SIZE, inp);
	
			sort_string_descending(string);
			printf("Sorted the %d string ascending: %s\n", i, string);
			i ++;
		}
	}
	else
		printf("Error!!!\n");

	fclose(inp);
	return 0;
}
