#include <iostream>
#include "LinearProbing.h"

using namespace std;


/**
 * Construct the hash table.
 */
HashTable_lp::HashTable_lp( const string & notFound, int size )
  : ITEM_NOT_FOUND( notFound ), array( nextPrime( size ) )
{
    makeEmpty( );
}

/**
 * Insert item x into the hash table. If the item is
 * already present, then do nothing.
 */
void HashTable_lp::insert( const string & x )
{
        // Insert x as active
    int currentPos = findPos( x );
    if( isActive( currentPos ) )
        return;
    array[ currentPos ] = HashEntry( x, ACTIVE );

        // Rehash
    if( ++currentSize > array.size( ) / 2 )
        rehash( );
}

/**
 * Expand the hash table.
 */
void HashTable_lp::rehash( )
{
    vector<HashEntry> oldArray = array;

        // Create new double-sized, empty table
    array.resize( nextPrime( 2 * oldArray.size( ) ) );
    for( int j = 0; j < array.size( ); j++ )
        array[ j ].info = EMPTY;

        // Copy table over
    currentSize = 0;
    for( int i = 0; i < oldArray.size( ); i++ )
        if( oldArray[ i ].info == ACTIVE )
            insert( oldArray[ i ].element );
}

/**
 * Method that performs quadratic probing resolution.
 * Return the position where the search for x terminates.
 */
int HashTable_lp::findPos( const string & x ) const
{
      int collisionNum = 0;
      int currentPos = hash( x, array.size( ) );

      while( array[ currentPos ].info != EMPTY &&
           array[ currentPos ].element != x )
    {
          currentPos++;
		  collisionNum++;  // Compute next probe
          if( currentPos >= array.size( ) )
              currentPos -= array.size( );
    }

      return currentPos;
}

/**
 * Method that performs quadratic probing resolution.
 * Return the number of collison where the search for x terminates.
 */
int HashTable_lp::collision( const string & x ) 
{
      int collisionNum = 0;
      int currentPos = hash( x, array.size( ) );

      while( array[ currentPos ].info != EMPTY &&
           array[ currentPos ].element != x )
    {
          currentPos++; 
		  collisionNum++;  // Compute next probe
          if( currentPos >= array.size( ) )
              currentPos -= array.size( );
    }

      return collisionNum;
}


/**
 * Remove item x from the hash table.
 */
void HashTable_lp::remove( const string & x )
{
    int currentPos = findPos( x );
    if( isActive( currentPos ) )
        array[ currentPos ].info = DELETED;
}

/**
 * Find item x in the hash table.
 * Return the matching item or ITEM_NOT_FOUND if not found
 */
const string & HashTable_lp::find( const string & x ) const
{
    int currentPos = findPos( x );
    if( isActive( currentPos ) )
        return array[ currentPos ].element;
    else
        return ITEM_NOT_FOUND;
}

/**
 * Make the hash table logically empty.
 */
void HashTable_lp::makeEmpty( )
{
    currentSize = 0;
    for( int i = 0; i < array.size( ); i++ )
        array[ i ].info = EMPTY;
}

/**
 * Deep copy.
 */
const HashTable_lp & HashTable_lp::
operator=( const HashTable_lp & rhs )
{
    if( this != &rhs )
    {
        array = rhs.array;
        currentSize = rhs.currentSize;
    }
    return *this;
}


/**
 * Return true if currentPos exists and is active.
 */
bool HashTable_lp::isActive( int currentPos ) const
{
    return array[ currentPos ].info == ACTIVE;
}

void HashTable_lp::insertLinearHT(vector<string> DataArray)
{
	int CollisionLinearHT = 0;
	cout<<"\n****************Linear HashTable**********************"<<endl;
	clock_t k2 = clock();
	clock_t start2 = clock();
	do start2 = clock();
	while (start2 == k2);

	for(int n = 0; n < DataArray.size(); n++)
	{
		//cout <<DataArray.at(n)<<endl;
		insert(DataArray.at(n));
	}

	clock_t end2 = clock();

	cout << "Total insertion elapsed time in seconds Linear: "
			<<(double)(end2 - start2)/CLOCKS_PER_SEC <<endl;
	cout <<"Average time per insertion Linear: "<<(double)(end2 - start2)/CLOCKS_PER_SEC/ DataArray.size()<< endl;

	for(int n = 0; n < DataArray.size(); n++)
		CollisionLinearHT += collision(DataArray.at(n));
	cout<<"Total number of collision Linear: "<<CollisionLinearHT<<endl;
}

void HashTable_lp::findLinearHT(vector<string> QueryArray)
{
	clock_t k3 = clock();
	clock_t start3 = clock();
	do start3 = clock();
	while (start3 == k3);

	for(int n = 0; n < QueryArray.size(); n++)
	{
		//cout <<QueryArray.at(n)<<endl;
		find(QueryArray.at(n));
	}

	clock_t end3 = clock();

	cout << "\nTotal search elapsed time in seconds Linear: "
			<<(double)(end3 - start3)/CLOCKS_PER_SEC <<endl;
	cout <<"Average time per search Linear: "<<(double)(end3 - start3)/CLOCKS_PER_SEC/ QueryArray.size()<< endl;

}