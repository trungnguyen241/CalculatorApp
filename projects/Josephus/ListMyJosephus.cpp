#include "ListMyJosephus.h"
#include<ctime>

//constructor
ListMyJosephus::ListMyJosephus(){
	this->M = 0;
	this->N = 0;
	this->size = 0;
	this->headPtr = NULL;
}

ListMyJosephus::ListMyJosephus(int N, int M){
	this->M = M;
	this->N = N;
	this->headPtr = NULL;
}
//destructor
ListMyJosephus::~ListMyJosephus(){
}

//setter and getter for the variable
void ListMyJosephus::setHeadPtr(Person *headPtr){
	this->headPtr = headPtr;}

Person* ListMyJosephus::getHeadPtr(){
	return (this->headPtr);}

void ListMyJosephus::setM(int newM){
	this->M = newM;}

int ListMyJosephus::getM(){
	return (this->M);}

void ListMyJosephus::setN(int newN){
	this->N = newN;}

int ListMyJosephus::getN(){
	return (this->N);}

void ListMyJosephus::setSize(int newSize){
	this->size = newSize;}

int ListMyJosephus::getSize(){
	return (this->size);}

//clear the whole circle by delete the node
void ListMyJosephus::clear(){
	Person *temp, *deletePtr = NULL;

	temp = headPtr;
	while (temp != NULL){
		deletePtr = temp;
		temp = temp->getNextPtr();
		delete deletePtr;
	}
}

//return the current size of the circle
int ListMyJosephus::currentSize(){
	Person *curr = headPtr;
	this->size = 0;

	while(curr->nextPtr != headPtr){
		this->size ++;
		curr = curr->getNextPtr();
	}
	return (this->size + 1);
}

//check whether the circle is empty
bool ListMyJosephus::isEmpty(){
	return (headPtr == NULL);
}

//determine to eliminate the next player by user input M
void ListMyJosephus::eliminateNext(int m)
{
	Person *player,*temp;
	int round = 1;
	int position[2048] = {0};
	double tempAvarage = 0.0, sumAvarage = 0.0;

	while(headPtr != headPtr->nextPtr)
	{
		player = headPtr;	
		for(int i = 0; i < m;i ++)
		{
			temp = player;
			player = player->nextPtr;
		}

		position[round] = player->position;
		//cout<<player->position<<" ";
		temp->nextPtr = player->nextPtr;
		delete player;
		headPtr = temp->nextPtr;

		cout<<"\nRound "<<round<<": Player left: ";
		printAll();
		cout<<"\n-->Current Size: "<<currentSize()<<"\n";
		round ++;
	}
	cout<<"\nPlayer Remove in Order: ";
	for (int i = 1; i < round; i++)
		cout<<position[i]<<" ";
		
}

//output extraction
ostream &operator<< (ostream &output, ListMyJosephus &rhs){
	Person *curr = rhs.headPtr;

	while(curr != NULL){
		output<<"Position:"<< curr->position;
		output<<"\n-->\n";

		curr = curr->nextPtr;
	}
	output<<"NULL\n";

	return output;
}

//print out the whole circle
void ListMyJosephus::printAll(){
	Person *curr = headPtr;

	while(curr->nextPtr != headPtr){

		cout<< curr->position<<"  ";
		curr = curr->nextPtr;
	}
	cout<< curr->position;
}

//create the list of player by user input N
void ListMyJosephus::createList(int n)
{
	Person *player;
	player = headPtr;

	player = new Person();

	player->position = 0;
	player->nextPtr = NULL;
	headPtr = player;

	for(int i = 1;i < n;i ++)
	{
		Person *temp = new Person();
		temp->position = i;
		temp->nextPtr = NULL;
		player = headPtr;
		while(player->nextPtr != NULL)
			player = player->nextPtr;
		player->nextPtr = temp;
	}
	player = player->nextPtr;
	player->nextPtr = headPtr;
}