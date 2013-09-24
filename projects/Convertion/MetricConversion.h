/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 121, Fall 2011																	*	
* Programming Assignment 8: Strings and Pointers												*	
* Date: Dec 07, 2011																			*
* Description: This program convert between the metric and english system. The program will		*
*				show error message if an invalid conversion is encountered						*
*************************************************************************************************/
#ifndef METRICCONVERTION_H
#define METRICCONVERTION_H

#include <stdio.h>
#include <stdlib.h>

#define TEN 10
#define HUND 100
#define THOUS 1000
#define TEN_THOUS 10000
#define HUND_THOUS 100000
#define MIL 1000000

int determine_conversion(char *token[50], char *englishLength[], char *metricLength[], double tokenNum);

#endif