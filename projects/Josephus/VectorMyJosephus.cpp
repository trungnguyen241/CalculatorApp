#include "VectorMyJosephus.h"
//constructor
VectorMyJosephus::VectorMyJosephus(){
	this->player = 0;
	this->size = 0;
	this->N = 0;
	this->M = 0;
}

VectorMyJosephus::VectorMyJosephus(int N, int M){
	this->player = 0;
	this->size = 0;
	this->N = N;
	this->M = M;
}
//destructor
VectorMyJosephus::~VectorMyJosephus(){
	delete [] player;
}

//play the game by user input number of player N and number of turn to eliminate player M
void VectorMyJosephus::play(int n, int m)
{
	int *player, *playerLeft;
	int number, order;
	int i = 0, j = 0, na = 0;
	
	number = n;
	player = new int[n];
	player[na] = 0;
	playerLeft = new int[n];

	while (number > 1){		//check if there is still player in the circle
		

		if (Alive(player, na, i))		//check if player is alive
		{		
			if (j == m)
			{
				player[na] = i;
				na++;
				j = 0;
				number --;
				
			}
			else{
				j++;
			}

			i++;	
		}
		else {
			i++;
		}

		if (i == n)
			i = 0;
	}

	cout<< "\nPlayer Removed in Order: ";
	for(int k = 0; k < na; k++)
		cout << player[k] << " ";

	delete []player;
}

//checking whether the player is alive or not
bool VectorMyJosephus::Alive(int *temp, int n, int i)
{
	for (int k = 0; k < n; k++)
		if (temp[k] == i)
			return false;

	return true;
}



//clear the circle
void VectorMyJosephus::clear(){
	for (int i = 0; i < N; i ++)
		player[i] = 0;
}

//return the current size of the circle
int VectorMyJosephus::currentSize(){
	this->size = 0;
	while(player[size+1] != NULL)
		size++;
	return (size + 1);
}

//check whether the circle is empty
bool VectorMyJosephus::isEmpty(){
	return (this->N == 0);
}
