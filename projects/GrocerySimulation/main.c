/********************************************************************************************************
* Programmer: Trung Nguyen																				*
* Class: Cpt S 122, Spring 2012																			*	
* Programming Assignment 04:  Grocery Store Simulation													*	
* Date: February 24, 2012																				*
* Description: This program will simulate 2 queues as the normal line and express line. The program		*
*				will randomly generate the arrival time and service time for each person in each queue	*
*				and will also display a message indicate whether a person is added to a line or to be	*
*				removed from a line. After every 10 minutes, the program will print out the whole		*
*				queue of each type.																		*	
*********************************************************************************************************/

#include "grocery.h"

int main(void)
{
	NormalNode normalQueue;
	ExpressNode expressQueue;
	int minute = 0;
	char answer = '\0';

	initNode(&normalQueue, &expressQueue);

	printf("Please input the amount of time in minutes you want to simulate: ");
	scanf("%d", &minute);

	simulation(normalQueue, expressQueue, minute);
	
	return 0;
}
