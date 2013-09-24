#include <fstream>
#include <iostream>
#include <vector>

#include "Chaining.h"
#include "QuadraticProbing.h"
#include "LinearProbing.h"
using namespace std;

int main( )
{
	vector<string> DataArray;
	vector<string> QueryArray;
	string word;
	int dataCount = 0, queryCount = 0;
	int CollisionsChainingHT = 0, CollisionLinearHT = 0, CollisionQuadraticHT = 0;
	int CollisionSimple = 0, CollisionPre = 0;
	
	string ITEM_NOT_FOUND = "ITEM_NOT_FOUND";
	HashTable_chaining ChainingHT( ITEM_NOT_FOUND, 101 );
	HashTable_qp QuadraticProbingHT ( ITEM_NOT_FOUND, 101 );
	HashTable_lp LinearProbingHT( ITEM_NOT_FOUND, 101 );


	ifstream DataArrayFile("OHenry.txt");
	ifstream QueryArrayFile("queries.txt");

	while(DataArrayFile >> word)
	{
		DataArray.push_back(word);
		dataCount ++;
	}
	cout<<"\nTotal number of words in OHenry file: "<<dataCount<<endl;

	while(QueryArrayFile >> word)
	{
		QueryArray.push_back(word);
		queryCount++;
	}
	cout<<"\nTotal number of words in Queries file: "<<queryCount<<endl;

/****************************AIM 1******************************/

//Chaining Hash Table
	ChainingHT.insertChainingHT(DataArray);
	ChainingHT.findChainingHT(QueryArray);

//Linear HashTable
	LinearProbingHT.insertLinearHT(DataArray);
	LinearProbingHT.findLinearHT(QueryArray);

//Quadratic HashTable/Full Length
	QuadraticProbingHT.insertQuadraticHT(DataArray, 0);
	QuadraticProbingHT.findQuadraticHT(QueryArray, 0);
	


/****************************AIM 2******************************/

//Simple HashTable
	QuadraticProbingHT.insertQuadraticHT(DataArray, 1);
	QuadraticProbingHT.findQuadraticHT(QueryArray, 1);

//Pre HashTable
	QuadraticProbingHT.insertQuadraticHT(DataArray, 2);
	QuadraticProbingHT.findQuadraticHT(QueryArray, 2);


	return 0;
}
