#include "Person.h"
//constructor
Person::Person(){
	this->position = 0;
}

Person::Person(int newPosition){
	this->position = newPosition;
}
//destructor
Person::~Person(){
}
//setter and getter for the variable
void Person::setPosition(int newPosition){
	this->position = newPosition;
}

int Person::getPosition(){
	return (this->position);
}

void Person::setNextPtr(Person *newPtr){
	this->nextPtr = newPtr;
}

Person* Person::getNextPtr(){
	return (this->nextPtr);
}

