
#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include <string>

using namespace std;

class Person {

	public: 
		Person();
		Person (int newPosition);
		~Person();
		
		void print();
		void setPosition(int newPosition);
		int getPosition();
		void setNextPtr(Person * newPtr);
		Person* getNextPtr();


	public:
		Person *nextPtr;	//next pointer
		int position;		//position of player
};
 
#endif