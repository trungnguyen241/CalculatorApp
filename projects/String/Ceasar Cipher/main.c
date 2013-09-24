/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 122, Spring 2012																	*	
* Programming Assignment 01: Ceasar Shift Cipher												*	
* Date: January 25, 2012																		*
* Description: This program read the string from a file. it will then ask user to input the		*
*				option to either encrypts or decrypts, and the number of place user wants to	*
*				shift the string. Then display out the result.									*
*************************************************************************************************/

#include "CeasarCipher.h"

int main(void)
{
	FILE *inp = NULL;
	char string[SIZE];
	int shift_value = 0, option = 0;

	display_test_driver();

	inp  = fopen("inp.txt", "r");
	fgets(string, SIZE, inp);
	printf("The current string is: %s\n\n", string);

	option_menu(&option, &shift_value);

	if(option == 1)
	{
		cipher_encrypts(string, shift_value);
		printf("\nCipher Encrypts: %s\n", string);
	}
	else if (option == 2)
	{
		cipher_decrypts(string, shift_value);
		printf("\nCipher Decrypts: %s\n", string);
	}
	else
		printf("Error!!!\n");

	fclose(inp);
	return 0;
}
