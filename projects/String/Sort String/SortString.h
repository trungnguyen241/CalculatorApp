/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 122, Spring 2012																	*	
* Programming Assignment 01: Sort String														*	
* Date: January 25, 2012																		*
* Description: This program read the string from a file, then it will sort the string in		*
*				ascending or descending order based on the user input. THe program then will	*
*				display out the result															*
*************************************************************************************************/

#ifndef SORTSTRING_H
#define SORTSTRING_H

#include<stdio.h>
#define SIZE 100

void sort_string_ascending(char *string);
void sort_string_descending(char *string);
void display_test_driver(void);

#endif