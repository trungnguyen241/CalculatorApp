#include <iostream>
#include "Chaining.h"

using namespace std;

/**
 * Construct the hash table.
 */
HashTable_chaining::HashTable_chaining( const string & notFound, int size )
  : ITEM_NOT_FOUND( notFound ), theLists( nextPrime( size ) )
{
}

/**
 * Insert item x into the hash table. If the item is
 * already present, then do nothing.
 */
 int HashTable_chaining::insert( const string & x )
{
    list<string>&  whichList = theLists[ hash( x, theLists.size( ) ) ];

	// search to make sure element not present
	for(list<string>::iterator itr=whichList.begin();itr!=whichList.end();itr++)
		if(*itr==x) 
			return 1;

	whichList.push_back(x);

	return 0;
}

/**
 * Remove item x from the hash table.
 */
void HashTable_chaining::remove( const string & x )
{
	int hash_index = hash( x, theLists.size( ) ) ;

    list<string>&  whichList = theLists[ hash_index ];

	// search to make sure element not present
	for(list<string>::iterator itr=whichList.begin();itr!=whichList.end();itr++) {
		if(*itr==x) {
   			theLists[hash_index].erase(itr);
			return;
		}
	}
	// element not found - so nothing to remove
}

/**
 * Find item x in the hash table.
 * Return the matching item or ITEM_NOT_FOUND if not found
 */
const string & HashTable_chaining::find( const string & x ) const
{
	int hash_index = hash( x, theLists.size( ) ) ;

    const list<string>&  whichList = theLists[ hash_index ];

	// search to make sure element not present
	for(list<string>::const_iterator itr=whichList.begin();itr!=whichList.end();itr++) {
		if(*itr==x) {
			return *itr;
		}
	}
	// element not found 
    return ITEM_NOT_FOUND;
}

/**
 * Make the hash table logically empty.
 */
void HashTable_chaining::makeEmpty( )
{
    for( int i = 0; i < theLists.size( ); i++ )
        theLists[ i ].clear( );
}

/**
 * Deep copy.
 */
const HashTable_chaining &
HashTable_chaining::operator=( const HashTable_chaining & rhs )
{
    if( this != &rhs )
        theLists = rhs.theLists;
    return *this;
}

 void HashTable_chaining::insertChainingHT(vector<string> DataArray)
 {
	int CollisionsChainingHT = 0;
	cout<<"\n****************Chaining HashTable**********************"<<endl;
	clock_t k = clock();
	clock_t start = clock();
	do start = clock();
	while (start == k);

	for(int n = 0; n < DataArray.size(); n++)
	{
		//cout <<DataArray.at(n)<<endl;
		CollisionsChainingHT += insert(DataArray.at(n));
	}
	clock_t end = clock();

	cout << "Total insertion elapsed time in seconds Channing: "
			<<(double)(end - start)/CLOCKS_PER_SEC <<endl;
	cout <<"Average time per insertion Channing: "<<(double)(end - start)/CLOCKS_PER_SEC/ DataArray.size()<< endl;

	CollisionsChainingHT = DataArray.size() - 101 - CollisionsChainingHT;
	cout<<"Total number of collision Channing: "<<CollisionsChainingHT<<endl;
 }

void HashTable_chaining::findChainingHT(vector<string> QueryArray)
{
	clock_t k1 = clock();
	clock_t start1 = clock();
	do start1 = clock();
	while (start1 == k1);

	for(int n = 0; n < QueryArray.size(); n++)
	{
		//cout <<QueryArray.at(n)<<endl;
		find(QueryArray.at(n));
	}
	clock_t end1 = clock();

	cout << "\nTotal search elapsed time in seconds Channing: "
			<<(double)(end1 - start1)/CLOCKS_PER_SEC <<endl;
	cout <<"Average time per search Channing: "<<(double)(end1 - start1)/CLOCKS_PER_SEC/ QueryArray.size()<< endl;
}
