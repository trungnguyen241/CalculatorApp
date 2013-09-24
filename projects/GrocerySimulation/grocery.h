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

#ifndef PA4_H
#define PA4_H

#include <stdio.h>
#include <stdlib.h>

#define MIN_PER_DAY 1440

typedef struct nL	//normal lane
{
	int customerNumber;
	int serviceTime;
	int totalTime;

	struct nL *pNext;
}NL;
typedef struct normalNode	//normal lane
{
	NL *head;
	NL *tail;
}NormalNode;

typedef struct eL	//express lane
{
	int customerNumber;
	int serviceTime;
	int totalTime;

	struct eL *pNext;
}EL;
typedef struct expressNode	//express lane
{
	NL *head;
	NL *tail;
}ExpressNode;


void initNode(NormalNode *normalQueue, ExpressNode *expressQueue);

int isNormalEmpty(NormalNode normalQueue);
int isExpressEmpty(ExpressNode expressQueue);

NL *makeNormalNode(int newNumber, int serviceTime, int totalTime);
EL *makeExpressNode(int newNumber, int serviceTime, int totalTime);

void printQueue(NormalNode normalQueue, ExpressNode expressQueue);

int enQueueNormal(NormalNode *normalQueue, NL *newNode);
void deQueueNormal (NormalNode *normalQueue);

int enQueueExpress(ExpressNode *expressQueue, EL *newNode);
void deQueueExpress (ExpressNode *expressQueue);

void simulation(NormalNode normalQueue, ExpressNode expressQueue, int minute);


#endif