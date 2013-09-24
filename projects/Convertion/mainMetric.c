/************************************************************************************************
* Programmer: Trung Nguyen																		*
* Class: Cpt S 121, Fall 2011																	*	
* Programming Assignment 8: Strings and Pointers												*	
* Date: Dec 07, 2011																			*
* Description: This program convert between the metric and english system. The program will		*
*				show error message if an invalid conversion is encountered						*
*************************************************************************************************/
#include "MetricConversion.h"

int main(void)
{
	int i = 0, j = 0, error = 0;
	double tokenNum = 0.0;
	char question [50], *token[50], option = '\0';
	char *englishLength[] = {"inches" , "quarts" , "pounds" ,"feet"};
	char *metricLength[] = {"milli", "centi", "deci", "deka", "hecto", "kilo"};

	do
	{
		printf("Type question in form: how many <...> are in X <...>\n>>");
		gets(question);

		token[0] = strtok(question, " ");
		i++;

		while((token[i] = strtok(NULL, " ")) != NULL)
			i++;

		tokenNum = atof(token[5]);

		error = determine_conversion(token, englishLength, metricLength, tokenNum);

		printf("Do you want to do another convertion? <y/n>: ");
		scanf("%c", &option);

	}while(error);

	return 0;
}