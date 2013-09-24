/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 122, Spring 2012																	*	
* Programming Assignment 01: Palindrome															*	
* Date: January 25, 2012																		*
* Description: This program read the string from a file, determine whether the string is a		*
*				palindrome or not, and display the result to the screen							*
*************************************************************************************************/

#ifndef PALINDROME_H
#define PALINDROME_H

#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

void remove_punct_and_make_lower_case(char *ch);
void reverse_string(char *string);
void determine_palindrome(char *string, char *new_string);


#endif