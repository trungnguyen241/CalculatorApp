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

/*********************************************************************************************************
 * Function: initNode ()                                    
 * Date Created: Feb 24, 2012                          
 * Date Last Modified: Feb 24, 2012                    
 * Description: initialize the queue to null
 * Input parameters : the normal and express queue
 * Output parameters: none
 * Returns: none                                  
 * Preconditions: the normal and express queue has already read in
 * Postconditions: none
 ***********************************************************************************************************/
void initNode(NormalNode *normalQueue, ExpressNode *expressQueue)
{
	normalQueue->head = NULL;
	normalQueue->tail = NULL;

	expressQueue->head = NULL;
	expressQueue->tail = NULL;
}

/*********************************************************************************************************
 * Function: isNormalEmpty ()                                    
 * Date Created: Feb 24, 2012                          
 * Date Last Modified: Feb 24, 2012                    
 * Description: check if the queue is empty
 * Input parameters : the normal queue
 * Output parameters: the status of the check
 * Returns: 1 if the queue is empty                                  
 * Preconditions: the normal queue has already read in
 * Postconditions: 1 if the queue is empty; 0 otherwise  
 ***********************************************************************************************************/
int isNormalEmpty(NormalNode normalQueue)
{
	return (normalQueue.head == NULL);
}

/*********************************************************************************************************
 * Function: isExpressEmpty ()                                    
 * Date Created: Feb 24, 2012                          
 * Date Last Modified: Feb 24, 2012                    
 * Description: check if the queue is empty
 * Input parameters : the express queue
 * Output parameters: none
 * Returns: 1 if the queue is empty                                  
 * Preconditions: the express queue has already read in
 * Postconditions: 1 if the queue is empty; 0 otherwise  
 ***********************************************************************************************************/
int isExpressEmpty(ExpressNode expressQueue)
{
	return (expressQueue.head == NULL);
}

/*********************************************************************************************************
 * Function: makeNormalNode ()                                    
 * Date Created: Feb 24, 2012                          
 * Date Last Modified: Feb 24, 2012                    
 * Description: make the new normal node 
 * Input parameters : the customer number, service time, and total time
 * Output parameters: none
 * Returns: the new node that has been created
 * Preconditions: the customer number, service time, and total time has already read in
 * Postconditions: the new node that has been created  
 ***********************************************************************************************************/
NL *makeNormalNode(int newNumber, int serviceTime, int totalTime)
{
	NL *pMem = NULL;

	pMem = (NL *) malloc(sizeof(NL));

	if(pMem != NULL)
	{
		pMem->customerNumber = newNumber;
		pMem->serviceTime = serviceTime;
		pMem->totalTime = totalTime;
		pMem->pNext = NULL;
	}

	return pMem;
}

/*********************************************************************************************************
 * Function: makeExpressNode ()                                    
 * Date Created: Feb 24, 2012                          
 * Date Last Modified: Feb 24, 2012                    
 * Description: make the new express node 
 * Input parameters : the customer number, service time, and total time
 * Output parameters: none
 * Returns: the new node that has been created
 * Preconditions: the customer number, service time, and total time has already read in
 * Postconditions: the new node that has been created  
 ***********************************************************************************************************/
EL *makeExpressNode(int newNumber, int serviceTime, int totalTime)
{
	EL *pMem = NULL;

	pMem = (NL *) malloc(sizeof(EL));

	if(pMem != NULL)
	{
		pMem->customerNumber = newNumber;
		pMem->serviceTime = serviceTime;
		pMem->totalTime = totalTime;
		pMem->pNext = NULL;
	}

	return pMem;
}

/*********************************************************************************************************
 * Function: printQueue ()                                    
 * Date Created: Feb 24, 2012                  
 * Date Last Modified: Feb 24, 2012          
 * Description: display 2 queues to the screen
 * Input parameters : the normal and express node
 * Output parameters: none
 * Returns: none
 * Preconditions: the normal and express node has been read in
 * Postconditions: none
 ***********************************************************************************************************/
void printQueue(NormalNode normalQueue, ExpressNode expressQueue)
{
	puts("************** Normal Lane ********************");
	while (!isNormalEmpty (normalQueue)) 
	{	
		printf ("Customer number: %d\n", (normalQueue.head)->customerNumber);
		printf ("Estimate services time : %d\n", (normalQueue.head)->serviceTime);
		printf ("Estimate total time: %d\n", (normalQueue.head)->totalTime);
		puts("->");
		normalQueue.head = (normalQueue.head)->pNext;
	}

	printf ("End of normal line\n\n");

	puts("************* Express Lane ********************");
	while (!isExpressEmpty (expressQueue)) 
	{	
		printf ("Customer number: %d\n", (expressQueue.head)->customerNumber);
		printf ("Estimate services time : %d\n", (expressQueue.head)->serviceTime);
		printf ("Estimate total time: %d\n", (expressQueue.head)->totalTime);
		puts("->");
		expressQueue.head = (expressQueue.head)->pNext;
	}

	printf ("End of express line\n\n");
	puts("***********************************************");
}

/*********************************************************************************************************
 * Function: enQueueNormal ()                                    
 * Date Created: Feb 24, 2012                          
 * Date Last Modified: Feb 24, 2012                    
 * Description: add the new node into the end of the queue 
 * Input parameters : the normal queue and the new node that will be added
 * Output parameters: none
 * Returns: the status of insertion
 * Preconditions: the normal queue and new node has been read in
 * Postconditions: the status of insertion
 ***********************************************************************************************************/
int enQueueNormal(NormalNode *normalQueue, NL *newNode)
{
	int status = 0;
	if(newNode != NULL)
	{
		if (isNormalEmpty (*normalQueue))
			normalQueue -> head = newNode;
		else // Non empty
			normalQueue -> tail -> pNext = newNode;

		normalQueue -> tail = newNode;
	}

	return status;
}

/*********************************************************************************************************
 * Function: enQueueExpress ()                                    
 * Date Created: Feb 24, 2012                          
 * Date Last Modified: Feb 24, 2012                    
 * Description: add the new node into the end of the queue 
 * Input parameters : the express queue and the new node that will be added
 * Output parameters: none
 * Returns: the status of insertion
 * Preconditions: the express queue and new node has been read in
 * Postconditions: the status of insertion
 ***********************************************************************************************************/
int enQueueExpress(ExpressNode *expressQueue, EL *newNode)
{
	int status = 0;
	if(newNode != NULL)
	{
		if (isExpressEmpty (*expressQueue))
			expressQueue -> head = newNode;
		else // Non empty
			expressQueue -> tail -> pNext = newNode;

		expressQueue -> tail = newNode;
	}

	return status;
}

/*********************************************************************************************************
 * Function: deQueueNormal ()                                    
 * Date Created: Feb 24, 2012                          
 * Date Last Modified: Feb 24, 2012                    
 * Description: remove the first node of the queue 
 * Input parameters : the normal queue 
 * Output parameters: none
 * Returns: none
 * Preconditions: the normal queue has been read in
 * Postconditions: none
 ***********************************************************************************************************/
void deQueueNormal (NormalNode *normalQueue)
{
	NL *pMem = NULL;

	if (!isNormalEmpty (*normalQueue))
	{
		if (normalQueue->head == normalQueue->tail)
			normalQueue->tail = NULL;

		pMem = normalQueue->head;
		normalQueue->head = normalQueue->head->pNext;
		free (pMem);
	}
}

/*********************************************************************************************************
 * Function: deQueueExpress ()                                    
 * Date Created: Feb 24, 2012                          
 * Date Last Modified: Feb 24, 2012                    
 * Description: remove the first node of the queue 
 * Input parameters : the express queue 
 * Output parameters: none
 * Returns: none
 * Preconditions: the express queue has been read in
 * Postconditions: none
 ***********************************************************************************************************/
void deQueueExpress (ExpressNode *expressQueue)
{
	EL *pMem = NULL;

	if (!isExpressEmpty (*expressQueue))
	{
		if (expressQueue->head == expressQueue->tail)
			expressQueue->tail = NULL;

		pMem = expressQueue->head;
		expressQueue->head = expressQueue->head->pNext;
		free (pMem);
	}
}

/*********************************************************************************************************
 * Function: simulation ()                                    
 * Date Created: Feb 24, 2012                          
 * Date Last Modified: Feb 24, 2012                    
 * Description: simulate the 2 queues at the same time. Program will randomly generate arrival and 
				service time, and will display message if a person is added or removed from a line.
 * Input parameters : the normal and express queue, and the minute of simulation 
 * Output parameters: none
 * Returns: none
 * Preconditions: the normal and express queue, and the minute of simulation has been read in
 * Postconditions: none
 ***********************************************************************************************************/
void simulation(NormalNode normalQueue, ExpressNode expressQueue, int minute)
{
	NL *normalNode = NULL;
	int arrivalTimeNL = 0; 
    int departTimeNL = -1; 
    int customerNumberNL = 0;
    int serviceTimeNL = 0;
    int MAX_SERV_TIME_NL = serviceTimeNL;
    int totalWaitingTimeNL = 0;

	
	EL *expressNode = NULL;
	int arrivalTimeEL = 0; 
    int departTimeEL = -1; 
    int customerNumberEL = 0;
    int serviceTimeEL = 0;
    int MAX_SERV_TIME_EL = serviceTimeEL;
    int totalWaitingTimeEL = 0;

	int i = 1;
    int totalTime = 0; 

    srand((unsigned int)time(NULL));
	
	printf("Program will simulate in %d minute\n\n", minute);
    while(totalTime != minute) 
	{
		/**************************PROCESS NORMAL LINE***************************/

        if(totalTime == departTimeNL && !isNormalEmpty(normalQueue)) 
		{
			serviceTimeNL = (normalQueue.head)->serviceTime; 

			printf("Customer %d will LEFT NORMAL line\n\n",(normalQueue.head)->customerNumber);

			totalWaitingTimeNL += (totalTime - (normalQueue.head)->totalTime);
            deQueueNormal(&normalQueue);    

			if(!isNormalEmpty(normalQueue))
                departTimeNL =  serviceTimeNL + totalTime; 
        }

        if(totalTime == arrivalTimeNL)
		{ 
            customerNumberNL++;		
            serviceTimeNL =  (rand() % 6) + 3; 
            MAX_SERV_TIME_NL = (serviceTimeNL > MAX_SERV_TIME_NL ? serviceTimeNL:MAX_SERV_TIME_NL);

            if(isNormalEmpty(normalQueue))
                departTimeNL = totalTime + serviceTimeNL;

			normalNode = makeNormalNode(customerNumberNL,serviceTimeNL,arrivalTimeNL);
            enQueueNormal(&normalQueue,normalNode); 

            arrivalTimeNL += (rand() % 6) + 3; 
			printf("**NORMAL LINE**\nCustomer %d joins at: %d.\nEstimate seving time: %d\nNew customer will come after %d min\n\n",(normalQueue.tail)->customerNumber,(normalQueue.tail)->totalTime,(normalQueue.tail)->serviceTime,arrivalTimeNL);
        }

		/**************************PROCESS EXPRESS LINE***************************/

		 if(totalTime == departTimeEL && !isExpressEmpty(expressQueue)) 
		{
			serviceTimeEL = (expressQueue.head)->serviceTime; 

			printf("Customer %d will LEFT EXPRESS line\n\n",(expressQueue.head)->customerNumber);

			totalWaitingTimeEL += (totalTime - (expressQueue.head)->totalTime);
            deQueueNormal(&expressQueue);    

			if(!isExpressEmpty(expressQueue))
                departTimeEL =  serviceTimeEL + totalTime; 
        }

        if(totalTime == arrivalTimeEL)
		{ 
            customerNumberEL++;		
            serviceTimeEL =  (rand() % 4) + 1; 
            MAX_SERV_TIME_EL = (serviceTimeEL > MAX_SERV_TIME_EL ? serviceTimeEL:MAX_SERV_TIME_EL);

            if(isExpressEmpty(expressQueue))
                departTimeEL = totalTime + serviceTimeEL;

			expressNode = makeExpressNode(customerNumberEL,serviceTimeEL,arrivalTimeEL);
            enQueueNormal(&expressQueue,expressNode); 

            arrivalTimeEL += (rand() % 4) + 1; 
			printf("**EXPRESS LINE**\nCustomer %d joins at: %d.\nEstimate seving time: %d\nNew customer will come after %d min\n\n",(expressQueue.tail)->customerNumber,(expressQueue.tail)->totalTime,(expressQueue.tail)->serviceTime,arrivalTimeEL);
        }

		/**************************PRINT OUT BOTH LINE ***************************/
        if(totalTime == (10 * i))
		{
			printQueue(normalQueue, expressQueue);
			i ++;
		}

		if(totalTime == MIN_PER_DAY)
		{
			customerNumberNL = 0;
			customerNumberEL = 0;
		}

        totalTime++;
		printf("--Elapsed time = %d--\n\n", totalTime);

	}

	customerNumberNL = ((normalQueue.tail)->customerNumber - (normalQueue.head)->customerNumber)+ 1; //total no. of customers unserved in normal line

	customerNumberEL = ((expressQueue.tail)->customerNumber - (expressQueue.head)->customerNumber)+ 1; //total no. of customers unserved in express line

	printf("***STATISTIC (Will incorrect if time elapsed exceed 1440)***\n\n");
	printf("**NORMAL LINE:\nAverage waitting time: %d\nMaximum service time: %d\nTotal customers unserved: %d\n\n",totalWaitingTimeNL/customerNumberNL,MAX_SERV_TIME_NL,customerNumberNL);

	printf("**EXPRESS LINE:\nAverage waitting time: %d\nMaximum service time: %d\nTotal customers unserved: %d\n\n",totalWaitingTimeEL/customerNumberEL,MAX_SERV_TIME_EL,customerNumberEL);
}

