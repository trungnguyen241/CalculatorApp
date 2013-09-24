 
#include<ctime>
#include<iostream>
#include "Person.h"
#include "ListMyJosephus.h"
#include "VectorMyJosephus.h"

using namespace std;
int main(int argc,char *argv[]) {	
	ListMyJosephus list;
	VectorMyJosephus arrList;

	clock_t k = clock();
	clock_t start = clock();
	do start = clock();
	while (start == k);

	cout<<"\t\t--------Welcome to Game Josephus---------\n\n";
	list.clear();
	cout<<"\t\t--------Link List Game Josephus----------\n\n";
	cout<<"Input the total player N (Sum - N >1): ";
	cin>>list.N;
	cout<<"Input the order to eliminate M (Count - M >1): ";
	cin>>list.M;
	list.createList(list.N);
	cout<<"Player Before Game: ";
	list.printAll();
	cout<<"\n--Current Size: "<<list.currentSize();
	
	list.eliminateNext(list.M);

	cout<<"\n--------------------------------------------";
	cout<<"\nPlayer Remaining : ";
	list.printAll();

	clock_t end=clock();
		cout << "\nCPU elapsed time in miseconds: "
			<<(double)(end - start)/CLOCKS_PER_SEC <<endl;
		cout<<"Average elimination time: "<<((double)(end - start)/CLOCKS_PER_SEC)/(list.N - 1)<<endl;
	
/*-------------------------------------------------------------------
---------------------------------------------------------------------*/

	cout<<"\n\n\t\t--------Vector List Game Josephus----------\n";
	clock_t k2 = clock();
	clock_t start2 = clock();
    do start2 = clock();
    while (start2 == k);

	cout<<"\n\nInput the total player N (Sum - N >1): ";
	cin>>arrList.N;
	cout<<"Input the order to eliminate M (Count - M >1): ";
	cin>>arrList.M;
	
	arrList.play(arrList.N, arrList.M);
	
	clock_t end2=clock();
    
    cout << "\n\nCPU elapsed time in milliseconds: "
         <<(double)(end2 - start2)/CLOCKS_PER_SEC <<endl;
	cout<<"Average elimination time: "
		<<((double)(end2 - start2)/CLOCKS_PER_SEC)/(arrList.N - 1)<<endl;
	return (0);
}

