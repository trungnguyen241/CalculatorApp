#ifndef LINEAR_PROBING_H_
#define LINEAR_PROBING_H_

#include <vector>
#include <string>
#include<ctime>
#include "globalfunctions.h"


using namespace std;

/* LinearProbing Hash table class

 CONSTRUCTION: an initialization for ITEM_NOT_FOUND
               and an approximate initial size or default of 101
*/

/******************PUBLIC OPERATIONS**************
 void insert( x )       --> Insert x
 void remove( x )       --> Remove x
 Hashable find( x )     --> Return item that matches x
 void makeEmpty( )      --> Remove all items
*/

class HashTable_lp
{
  public:
    explicit HashTable_lp( const string& notFound, int size = 101 );
    HashTable_lp( const HashTable_lp & rhs )
      : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ),
        array( rhs.array ), currentSize( rhs.currentSize ) { }

    const string & find( const string & x ) const;

    void makeEmpty( );
    void insert( const string & x );
    void remove( const string & x );
    const HashTable_lp & operator=( const HashTable_lp & rhs );

	int collision( const string & x );
	void insertLinearHT(vector<string> DataArray);
	void findLinearHT(vector<string> QueryArray);

	enum EntryType { ACTIVE, EMPTY, DELETED };
  private:
    struct HashEntry
    {
        string element;
        EntryType info;

        HashEntry( const string & e = string( ), EntryType i = EMPTY )
          : element( e ), info( i ) { }
    };
    
    vector<HashEntry> array;
    int currentSize;
    const string ITEM_NOT_FOUND;

    bool isActive( int currentPos ) const;
    int findPos( const string & x ) const;
    void rehash( );
	
};

#endif
