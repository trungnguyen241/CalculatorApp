#include "TestListMyJosephus.h"
#include<ctime>

TestListMyJosephus::TestListMyJosephus(){
	this->player = NULL;
}

TestListMyJosephus::~TestListMyJosephus(){
}

void TestListMyJosephus::playGameList(){
	//ListMyJosephus list;

	clock_t k = clock();
    clock_t start = clock();
    do start = clock();
    while (start == k);

	cout<<"--------Welcome to Game Josephus---------\n";
	cout<<"Input the total player N (Sum - N >1): ";
	cin>>player->N;
	cout<<"Input the order to eliminate M (Count - M >1): ";
	cin>>player->M;
	player->createList(player->N);
	cout<<"Player Before Game: ";
	player->printAll();
	cout<<"\n--Current Size: "<<player->currentSize();
	cout<<"\nPlayer Remove in Order: ";

	player->eliminateNext(player->M);

	cout<<"\n--------------------------------------------";
	cout<<"\nPlayer Remaining : ";
	player->printAll();

	clock_t end = clock();
    
    cout << "\nCPU elapsed time in seconds: "
         <<(double)(end - start)/CLOCKS_PER_SEC <<endl;
	cout<<"Average elimination time: "
		<<((double)(end - start)/CLOCKS_PER_SEC)/(player->N - 1)<<endl;
}