#include "testQueue.h"
#include "Queue.h"

void testEnqueueEmpty (void)
{
	Queue q = {NULL, NULL}; // Empty queue

	enqueue (&q, "string"); // test case

	printf ("Result: %s\n", q.pHead -> strData);
	printf ("Addresses: tail: %d, head: %d\n",
			q.pTail, q.pHead);
}

void testDequeueNonEmpty (void)
{
	Queue q = {NULL, NULL}; // Empty queue
	char retStr[50];

	enqueue (&q, "string"); 

	printf ("Result: %s\n", q.pHead -> strData);

	dequeue (&q, retStr);

	printf ("Data dequeued: %s\n", retStr);//q.pHead ->strData);
	printf ("Addresses: tail: %d, head: %d\n",
			q.pTail, q.pHead);

	if ((q.pHead == NULL) && (q.pTail == NULL))
	{
		printf ("Test case passed!\n");
	}
	else
	{
		printf ("Test case failed!\n");
	}

}