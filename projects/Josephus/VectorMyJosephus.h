/*
 * VectorMyJosephus:
 * This class implements a MyJosephus circle using an STL vector
 * N : initial number of players
 * M : interval to jump for next removal
 *	
 * In your solution, make sure you have a separate .cpp file that defines the implementation for every .h file. 
 */

#ifndef __VectorMyJosephus_H__
#define __VectorMyJosephus_H__

#include <iostream>
#include <vector>

using namespace std;

class VectorMyJosephus {

public:
	VectorMyJosephus();	
	VectorMyJosephus(int N,int M);


	// Destructor: make sure you free everything you allocated.
	~VectorMyJosephus();

	bool Alive (int *temp, int n, int i);
	void clear();
	int currentSize();
	bool isEmpty();
	//void printAll();
	void play(int n, int m);

public:
	int *player; 

	int size;	
	int N;		
	int M;		
};



#endif