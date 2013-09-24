#ifndef CHAINING_H_
#define CHAINING_H_

#include<string>
#include<vector>
#include<list>
#include<ctime>
#include "globalfunctions.h"

using namespace std;

/*SeparateChaining Hash table class

 CONSTRUCTION: an initialization for ITEM_NOT_FOUND
               and an approximate initial size or default of 101
*/

/****************PUBLIC OPERATIONS****************
 void insert( x )       --> Insert x
 void remove( x )       --> Remove x
 Hashable find( x )     --> Return item that matches x
 void makeEmpty( )      --> Remove all items
 int hash( string str, int tableSize )
                        --> Global method to hash strings
*/

class HashTable_chaining
{
  public:
    explicit HashTable_chaining( const string & notFound, int size = 101 );
    HashTable_chaining( const HashTable_chaining &rhs )
      : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ), theLists( rhs.theLists ) { }

    const string & find( const string & x ) const;

    void makeEmpty( );
    int insert( const string & x );
    void remove( const string & x );

    const HashTable_chaining & operator=( const HashTable_chaining & rhs );

	void insertChainingHT(vector<string> DataArray);
	void findChainingHT(vector<string> QueryArray);

  private:
    vector< list<string> > theLists;   // The array of Lists
    const string ITEM_NOT_FOUND;
};
#endif
