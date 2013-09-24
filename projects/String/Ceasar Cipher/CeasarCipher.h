/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 122, Spring 2012																	*	
* Programming Assignment 01: Ceasar Shift Cipher												*	
* Date: January 25, 2012																		*
* Description: This program read the string from a file. it will then ask user to input the		*
*				option to either encrypts or decrypts, and the number of place user wants to	*
*				shift the string. Then display out the result.									*
*************************************************************************************************/

#ifndef CEASARCIPHER_H
#define CEASARCIPHER_H

#include <stdio.h>
#define SIZE 50

void display_test_driver(void);
void option_menu(int *option);
void cipher_encrypts(char *ch, int shift_value);
void cipher_decrypts(char *ch, int shift_value);

#endif 