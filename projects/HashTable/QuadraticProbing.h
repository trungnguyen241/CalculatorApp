#ifndef QUADRATIC_PROBING_H_
#define QUADRATIC_PROBING_H_

#include <vector>
#include <string>
#include<ctime>
#include "globalfunctions.h"


using namespace std;

/* QuadraticProbing Hash table class

 CONSTRUCTION: an initialization for ITEM_NOT_FOUND
               and an approximate initial size or default of 101
*/

/******************PUBLIC OPERATIONS**************
 void insert( x )       --> Insert x
 void remove( x )       --> Remove x
 Hashable find( x )     --> Return item that matches x
 void makeEmpty( )      --> Remove all items
*/

class HashTable_qp
{
  public:
    explicit HashTable_qp( const string& notFound, int size = 101 );
    HashTable_qp( const HashTable_qp & rhs )
      : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ),
        array( rhs.array ), currentSize( rhs.currentSize ) { }

    const string & find( const string & x, int hashOption ) const;

    void makeEmpty( );
    void insert( const string & x, int hashOption);

	int collision( const string & x, int hashOption);
	void insertQuadraticHT(vector<string> DataArray, int hashOption);
	void findQuadraticHT(vector<string> QueryArray, int hashOption);

/****************************************/
	int findPosUsingSimpleHash( const string & x ) const;
	int collisionUsingSimpleHash( const string & x );
	const string & findUsingSimpleHash( const string & x ) const;
	void insertUsingSimpleHash( const string & x );
	void rehashUsingSimpleHash( );


	int findPosUsingPreHash( const string & x ) const;
	int collisionUsingPreHash( const string & x );
	const string & findUsingPreHash( const string & x ) const;
	void insertUsingPreHash( const string & x );
	void rehashUsingPreHash( );


    const HashTable_qp & operator=( const HashTable_qp & rhs );

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
    int findPos( const string & x, int hashOption) const;
    void rehash( int hashOption );
};
#endif
