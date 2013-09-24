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

/*********************************************************************************************************
 * Function: option_menu ()                                    
 * Date Created: January 22, 2012                          
 * Date Last Modified: January 22, 2012                    
 * Description: This function is used to display the option menu to the main screen and let the user 
 *				choose the options and the shift value to the string
 * Input parameters : None  
 * Output parameters: The pointer to option and shift value of type integer
 * Returns: none                                     
 * Preconditions: none                
 * Postconditions: The output of option and shift value                     
 ***********************************************************************************************************/
void option_menu(int *option, int *shift_value)
{
	printf("Please choose the option:\n");
	printf("1.Cipher Encrypts\n2.Cipher Decrypts\n--->");
	scanf("%d", option);
	printf("Enter the shift value: ");
	scanf("%d", shift_value);
}

/*********************************************************************************************************
 * Function: cipher_encrypts ()                                    
 * Date Created: January 22, 2012                          
 * Date Last Modified: January 22, 2012                    
 * Description: This function is used to convert each character in string into upper case and encrypts
 *				the string based on the number of shift
 * Input parameters : The pointer to the fisrt characer in the string and the shiftt value  
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The string and the shift value have been read in
 * Postconditions: none                     
 ***********************************************************************************************************/
void cipher_encrypts(char *ch, int shift_value)
{
	while(*ch)
	{
		if (islower(*ch))
			*ch = toupper(*ch);

		if(*ch != ' ')
		{
			*ch = (*ch) + shift_value;
			if(*ch > 90)
				*ch = *ch - 26;
		}
		ch++;
	}
}

/*********************************************************************************************************
 * Function: cipher_decrypts ()                                    
 * Date Created: January 22, 2012                          
 * Date Last Modified: January 22, 2012                    
 * Description: This function is used to convert each character in string into upper case and decrypts
 *				the string based on the number of shift
 * Input parameters : The pointer to the fisrt characer in the string and the shiftt value  
 * Output parameters: none
 * Returns: none                                     
 * Preconditions: The string and the shift value have been read in
 * Postconditions: none                     
 ***********************************************************************************************************/
void cipher_decrypts(char *ch, int shift_value)
{
	while(*ch)
	{
		if (islower(*ch))
			*ch = toupper(*ch);

		if(*ch != ' ')
		{
			*ch = (*ch) - shift_value;
			if(*ch < 65)
				*ch = *ch + 26;
		}
		ch++;
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
	char str1[SIZE] = "abcdefg,,,hjklmnopqrstuvwxyz";
	char str2[SIZE] = "wkh txlfn eurzq ira mxpsv ryhu wkh odcb grj";

	printf("************************************Test Driver********************************\n\n");
	printf("The test string is: %s\n", str1);
	cipher_encrypts(str1, 3);
	printf("Cipher encrypts rotates 3 places: %s\n\n", str1);

	printf("The test string is: %s\n", str2);
	cipher_decrypts(str2, 3);
	printf("Cipher decrypts rotates 3 places: %s\n", str2);
	printf("*******************************************************************************\n\n");
}