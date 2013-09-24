/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 121, Fall 2011																	*	
* Programming Assignment 8: Strings and Pointers												*	
* Date: Dec 07, 2011																			*
* Description: This program convert between the metric and english system. The program will		*
*				show error message if an invalid conversion is encountered						*
*************************************************************************************************/
#include "MetricConversion.h"

/*********************************************************************************************************
 * Function: determine_conversion ()                                    
 * Date Created: Dec 07, 2011                          
 * Date Last Modified: Dec 07, 2011                      
 * Description: This function determine what unit to do the conversion and then calculate and print 
 *				out the result. Error message will display if invalid conversion encoutered
 * Input parameters: *token[], *englishLength[], *metricLength[], and tokenNum
 * Preconditions: The *token[], *englishLength[], *metricLength[], and tokenNum has been read in             
 * Postconditions: none  
 * Return: the integer indicate error
 ***********************************************************************************************************/
int determine_conversion(char *token[], char *englishLength[], char *metricLength[], double tokenNum)
{
	double result = 0.0;
	int error = 0;
	int conversion_unit = 0;

	if(strncmp(token[2], englishLength[0], 5) == 0)
		conversion_unit = 1;
	else if (strncmp(token[2], englishLength[1], 5) == 0)
		conversion_unit = 2;
	else if (strncmp(token[2], englishLength[2], 5) == 0)
		conversion_unit = 3;
	else if (strncmp(token[2], englishLength[3], 4) == 0)
		conversion_unit = 4;
	else if (strncmp(token[2], metricLength[0], 4) == 0)
		conversion_unit = 5;
	else if (strncmp(token[2], metricLength[1], 4) == 0)
		conversion_unit = 6;
	else if (strncmp(token[2], metricLength[2], 4) == 0)
		conversion_unit = 7;
	else if (strncmp(token[2], metricLength[3], 4) == 0)
		conversion_unit = 8;
	else if (strncmp(token[2], metricLength[4], 4) == 0)
		conversion_unit = 9;
	else if (strncmp(token[2], metricLength[5], 4) == 0)
		conversion_unit = 10;

	switch(conversion_unit)
	{
		//convert from inches to feet and metric lenght
		case 1:
			if (strncmp(token[6], "millimeters", 10) == 0)
				result = tokenNum * 39370 / MIL;
			else if (strncmp(token[6], "centimeters", 10) == 0)
				result = tokenNum * 39370 / HUND_THOUS;
			else if (strncmp(token[6], "decimeters", 9) == 0)
				result = tokenNum * 39370 / TEN_THOUS;
			else if (strncmp(token[6], "dekameters", 9) == 0)
				result = tokenNum * 39370 / HUND;
			else if (strncmp(token[6], "hectometers", 10) == 0)
				result = tokenNum * 39370 / TEN;
			else if (strncmp(token[6], "kilometers", 9) == 0) 
				result = tokenNum * 39370;
			else if (strncmp(token[6], "feet", 4) == 0) 
				result = tokenNum * 12;
			else
				error = 1;
			break;
		
		//convert from quart metric volume
		case 2:
			if (strncmp(token[6], "milliliters", 10) == 0)
				result = tokenNum * 1057 / MIL;
			else if (strncmp(token[6], "centiliters", 10) == 0)
				result = tokenNum * 1057 / HUND_THOUS;
			else if (strncmp(token[6], "deciliters", 9) == 0)
				result = tokenNum * 1057 / TEN_THOUS;
			else if (strncmp(token[6], "dekaliters", 10) == 0)
				result = tokenNum * 1057 / HUND;
			else if (strncmp(token[6], "hectoliters", 10) == 0)
				result = tokenNum * 1057 / TEN;
			else if (strncmp(token[6], "kiloliters", 9) == 0) 
				result = tokenNum * 1057;
			else
				error = 1;
			break;

		//convert from pound metric weight
		case 3:
			if (strncmp(token[6], "milligrams", 9) == 0)
				result = tokenNum * 2.205 / MIL;
			else if (strncmp(token[6], "centigrams", 9) == 0)
				result = tokenNum * 2.205 / HUND_THOUS;
			else if (strncmp(token[6], "decigrams", 8) == 0)
				result = tokenNum * 2.205 / TEN_THOUS;
			else if (strncmp(token[6], "dekagrams", 8) == 0)
				result = tokenNum * 2.205 / HUND;
			else if (strncmp(token[6], "hectograms", 9) == 0)
				result = tokenNum * 2.205 / TEN;
			else if (strncmp(token[6], "kilograms", 8) == 0) 
				result = tokenNum * 2.205;
			else
				error = 1;
			break;

		//convert from geet metric length
		case 4:
			if (strncmp(token[6], "millimeters", 10) == 0)
				result = tokenNum * 3281 / MIL;
			else if (strncmp(token[6], "centimeters", 10) == 0)
				result = tokenNum * 3281 / HUND_THOUS;
			else if (strncmp(token[6], "decimeters", 9) == 0)
				result = tokenNum * 3281 / TEN_THOUS;
			else if (strncmp(token[6], "dekameters", 9) == 0)
				result = tokenNum * 3281 / HUND;
			else if (strncmp(token[6], "hectometers", 10) == 0)
				result = tokenNum * 3281 / TEN;
			else if (strncmp(token[6], "kilometers", 9) == 0) 
				result = tokenNum * 3281 ;
			else if (strncmp(token[6], "inches", 4) == 0) 
				result = tokenNum * .08333;
			else
				error = 1;
			break;

		case 5:
			//convert between metric system
			if (strncmp(token[2] + 5, token[6] + 5, 1) == 0)
			{
				if (strncmp(token[6], metricLength[0], 4) == 0) 
					result = tokenNum;
				else if (strncmp(token[6], metricLength[1], 5) == 0) 
					result = tokenNum / TEN;
				else if (strncmp(token[6], metricLength[2], 4) == 0) 
					result = tokenNum / HUND;
				else if (strncmp(token[6], metricLength[3], 4) == 0) 
					result = tokenNum / TEN_THOUS;
				else if (strncmp(token[6], metricLength[4], 5) == 0) 
					result = tokenNum / HUND_THOUS;
				else 
					result = tokenNum / MIL;
			}
			//convert from metric to english system
			else if ((strncmp(token[2], "millimeters", 10) == 0) && (strncmp(token[6], "inches", 5) == 0))
				result = tokenNum * 25.4;
			else if ((strncmp(token[2], "millimeters", 10) == 0) && (strncmp(token[6], "feet", 4) == 0))
				result = tokenNum * 304.8;
			else if ((strncmp(token[2], "milliliters", 10) == 0) && (strncmp(token[6], "quarts", 5) == 0))
				result = tokenNum * 946.4;
			else if ((strncmp(token[2], "milligrams", 9) == 0) && (strncmp(token[6], "pounds", 5) == 0))
				result = tokenNum * 453592;
			else
				error = 1;
			break;

		case 6:
			//convert between metric system
			if (strncmp(token[2] + 5, token[6] + 5, 1) == 0)
			{
				if (strncmp(token[6], metricLength[0], 4) == 0) 
					result = tokenNum * TEN;
				else if (strncmp(token[6], metricLength[1], 5) == 0) 
					result = tokenNum;
				else if (strncmp(token[6], metricLength[2], 4) == 0) 
					result = tokenNum / TEN;
				else if (strncmp(token[6], metricLength[3], 4) == 0) 
					result = tokenNum / THOUS;
				else if (strncmp(token[6], metricLength[4], 5) == 0) 
					result = tokenNum / TEN_THOUS;
				else 
					result = tokenNum / HUND_THOUS;
			}
			//convert from metric to english system
			else if ((strncmp(token[2], "centimeters", 10) == 0) && (strncmp(token[6], "inches", 5) == 0))
				result = tokenNum * 25.4 / TEN;
			else if ((strncmp(token[2], "centimeters", 10) == 0) && (strncmp(token[6], "feet", 4) == 0))
				result = tokenNum * 304.8 / TEN;
			else if ((strncmp(token[2], "centiliters", 10) == 0) && (strncmp(token[6], "quarts", 5) == 0))
				result = tokenNum * 946.4 / TEN;
			else if ((strncmp(token[2], "centigrams", 9) == 0) && (strncmp(token[6], "pounds", 5) == 0))
				result = tokenNum * 453592 / TEN;
			else
				error = 1;
			break;
		case 7:
			//convert between metric system
			if (strncmp(token[2] + 5, token[6] + 5, 1) == 0)
			{
				if (strncmp(token[6], metricLength[0], 4) == 0) 
					result = tokenNum * HUND;
				else if (strncmp(token[6], metricLength[1], 5) == 0) 
					result = tokenNum * TEN;
				else if (strncmp(token[6], metricLength[2], 4) == 0) 
					result = tokenNum;
				else if (strncmp(token[6], metricLength[3], 4) == 0) 
					result = tokenNum / HUND;
				else if (strncmp(token[6], metricLength[4], 5) == 0) 
					result = tokenNum / THOUS;
				else 
					result = tokenNum / TEN_THOUS;
			}
			//convert from metric to english system
			else if ((strncmp(token[2], "decimeters", 9) == 0) && (strncmp(token[6], "inches", 5) == 0))
				result = tokenNum * 25.4 / HUND;
			else if ((strncmp(token[2], "decimeters", 9) == 0) && (strncmp(token[6], "feet", 4) == 0))
				result = tokenNum * 304.8 / HUND;
			else if ((strncmp(token[2], "deciliters", 9) == 0) && (strncmp(token[6], "quarts", 5) == 0))
				result = tokenNum * 946.4 / HUND;
			else if ((strncmp(token[2], "decigrams", 8) == 0) && (strncmp(token[6], "pounds", 5) == 0))
				result = tokenNum * 453592 / HUND;
			else
				error = 1;
			break;
		case 8:
			//convert between metric system
			if (strncmp(token[2] + 5, token[6] + 5, 1) == 0)
			{
				if (strncmp(token[6], metricLength[0], 4) == 0) 
					result = tokenNum * TEN_THOUS;
				else if (strncmp(token[6], metricLength[1], 5) == 0) 
					result = tokenNum * THOUS;
				else if (strncmp(token[6], metricLength[2], 4) == 0) 
					result = tokenNum * HUND;
				else if (strncmp(token[6], metricLength[3], 4) == 0) 
					result = tokenNum;
				else if (strncmp(token[6], metricLength[4], 5) == 0) 
					result = tokenNum / TEN;
				else 
					result = tokenNum / HUND;
			}
			//convert from metric to english system
			else if ((strncmp(token[2], "dekameters", 9) == 0) && (strncmp(token[6], "inches", 5) == 0))
				result = tokenNum * 25.4 / TEN_THOUS;
			else if ((strncmp(token[2], "dekameters", 9) == 0) && (strncmp(token[6], "feet", 4) == 0))
				result = tokenNum * 304.8 / TEN_THOUS;
			else if ((strncmp(token[2], "dekaliters", 9) == 0) && (strncmp(token[6], "quarts", 5) == 0))
				result = tokenNum * 946.4 / TEN_THOUS;
			else if ((strncmp(token[2], "dekagrams", 8) == 0) && (strncmp(token[6], "pounds", 5) == 0))
				result = tokenNum * 453592 / TEN_THOUS;
			else
				error = 1;
			break;
		case 9:
			//convert between metric system
			if (strncmp(token[2] + 5, token[6] + 5, 1) == 0)
			{
				if (strncmp(token[6], metricLength[0], 4) == 0) 
					result = tokenNum * HUND_THOUS;
				else if (strncmp(token[6], metricLength[1], 5) == 0) 
					result = tokenNum * TEN_THOUS;
				else if (strncmp(token[6], metricLength[2], 4) == 0) 
					result = tokenNum * THOUS;
				else if (strncmp(token[6], metricLength[3], 4) == 0) 
					result = tokenNum * TEN;
				else if (strncmp(token[6], metricLength[4], 5) == 0) 
					result = tokenNum;
				else 
					result = tokenNum / TEN;
			}
			//convert from metric to english system
			else if ((strncmp(token[2], "hectometers", 10) == 0) && (strncmp(token[6], "inches", 5) == 0))
				result = tokenNum * 25.4 / HUND_THOUS;
			else if ((strncmp(token[2], "hectometers", 10) == 0) && (strncmp(token[6], "feet", 4) == 0))
				result = tokenNum * 304.8 / HUND_THOUS;
			else if ((strncmp(token[2], "hectoliters", 10) == 0) && (strncmp(token[6], "quarts", 5) == 0))
				result = tokenNum * 946.4 / HUND_THOUS;
			else if ((strncmp(token[2], "hectograms", 9) == 0) && (strncmp(token[6], "pounds", 5) == 0))
				result = tokenNum * 453592 / HUND_THOUS;
			else
				error = 1;
			break;
		case 10:
			if (strncmp(token[2] + 5, token[6] + 5, 1) == 0)
			{
				if (strncmp(token[6], metricLength[0], 4) == 0) 
					result = tokenNum / MIL;
				else if (strncmp(token[6], metricLength[1], 5) == 0) 
					result = tokenNum / HUND_THOUS;
				else if (strncmp(token[6], metricLength[2], 4) == 0) 
					result = tokenNum / TEN_THOUS;
				else if (strncmp(token[6], metricLength[3], 4) == 0) 
					result = tokenNum / HUND;
				else if (strncmp(token[6], metricLength[4], 5) == 0) 
					result = tokenNum / TEN;
				else 
					result = tokenNum;
			}
			//convert from metric to english system
			else if ((strncmp(token[2], "kilometers", 9) == 0) && (strncmp(token[6], "inches", 5) == 0))
				result = tokenNum * 25.4 / MIL;
			else if ((strncmp(token[2], "hectometers", 9) == 0) && (strncmp(token[6], "feet", 4) == 0))
				result = tokenNum * 304.8 / MIL;
			else if ((strncmp(token[2], "hectoliters", 9) == 0) && (strncmp(token[6], "quarts", 5) == 0))
				result = tokenNum * 946.4 / MIL;
			else if ((strncmp(token[2], "hectograms", 8) == 0) && (strncmp(token[6], "pounds", 5) == 0))
				result = tokenNum * 453592 / MIL;
			else
				error = 1;	
			break;
	}

	if(!error)
		printf("Result = %.5lf\n", result);
	else
		printf("Error, can not convert these unit. Please type another valid question.\n\n");

	return error;
}
