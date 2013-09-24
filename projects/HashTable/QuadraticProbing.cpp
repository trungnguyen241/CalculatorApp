#include <iostream>
#include "QuadraticProbing.h"

using namespace std;


/**
 * Construct the hash table.
 */
HashTable_qp::HashTable_qp( const string & notFound, int size )
  : ITEM_NOT_FOUND( notFound ), array( nextPrime( size ) )
{
    makeEmpty( );
}

/**
 * Insert item x into the hash table. If the item is
 * already present, then do nothing.
 */
void HashTable_qp::insert( const string & x, int hashOption )
{
        // Insert x as active
    int currentPos = findPos( x, hashOption );
    if( isActive( currentPos ) )
        return;
    array[ currentPos ] = HashEntry( x, ACTIVE );

        // Rehash; see Section 5.5
    if( ++currentSize > array.size( ) / 2 )
        rehash(hashOption);
}

/**
 * Expand the hash table.
 */
void HashTable_qp::rehash( int hashOption )
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
            insert( oldArray[ i ].element, hashOption );
}

/**
 * Method that performs quadratic probing resolution.
 * Return the position where the search for x terminates.
 */
int HashTable_qp::findPos( const string & x, int hashOption ) const
{
      int collisionNum = 0;
	  int currentPos = 0;

	  switch(hashOption)
	  {
		case 1:		//simple hash
			currentPos = simpleHash( x, array.size( ) );
			break;
		case 2:		//pre-hash
			currentPos = preHash( x, array.size( ) );
			break;
		case 3:		//full length hash
			currentPos = hash( x, array.size( ) );
			break;
	  }

      while( array[ currentPos ].info != EMPTY &&
           array[ currentPos ].element != x )
    {
          currentPos += 2 * ++collisionNum - 1;  // Compute ith probe
          if( currentPos >= array.size( ) )
              currentPos -= array.size( );
    }

      return currentPos;
}

/**
 * Method that performs quadratic probing resolution.
 * Return the number of collison where the search for x terminates.
 */
int HashTable_qp::collision( const string & x, int hashOption ) 
{
      int collisionNum = 0;
      int currentPos = 0;

	  switch(hashOption)
	  {
		case 1:		//simple hash
			currentPos = simpleHash( x, array.size( ) );
			break;

		case 2:		//pre-hash
			currentPos = preHash( x, array.size( ) );
			break;

		case 3:		//full length hash
			currentPos = hash( x, array.size( ) );
			break;
	  }

      while( array[ currentPos ].info != EMPTY &&
           array[ currentPos ].element != x )
    {
          currentPos += 2 * ++collisionNum - 1;  // Compute ith probe
          if( currentPos >= array.size( ) )
              currentPos -= array.size( );
    }

      return collisionNum;
}


/**
 * Find item x in the hash table.
 * Return the matching item or ITEM_NOT_FOUND if not found
 */
const string & HashTable_qp::find( const string & x, int hashOption ) const
{
    int currentPos = findPos( x, hashOption );
    if( isActive( currentPos ) )
        return array[ currentPos ].element;
    else
        return ITEM_NOT_FOUND;
}

/**
 * Make the hash table logically empty.
 */
void HashTable_qp::makeEmpty( )
{
    currentSize = 0;
    for( int i = 0; i < array.size( ); i++ )
        array[ i ].info = EMPTY;
}

/**
 * Deep copy.
 */
const HashTable_qp & HashTable_qp::
operator=( const HashTable_qp & rhs )
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
bool HashTable_qp::isActive( int currentPos ) const
{
    return array[ currentPos ].info == ACTIVE;
}

void HashTable_qp::insertQuadraticHT(vector<string> DataArray, int hashOption)
{
	int CollisionQuadraticHT = 0;
	int CollisionSimple = 0, CollisionPre = 0;

	clock_t k = clock();
	clock_t start = clock();
	do start = clock();
	while (start == k);

	switch(hashOption)
	{
		case 0:
		case 3:
			for(int n = 0; n < DataArray.size(); n++)
				insert(DataArray.at(n), 3);
			break;
		case 1:
			for(int n = 0; n < DataArray.size(); n++)
				insert(DataArray.at(n), 1);
			break;
		case 2:
			for(int n = 0; n < DataArray.size(); n++)
				insert(DataArray.at(n), 2);
			break;
	}
	clock_t stop = clock();

	switch (hashOption)
	{
		case 0:
		case 3:
			cout<<"\n****************Quadratic/Full Length HashTable**********************"<<endl;
			cout << "Total insertion elapsed time in seconds Quadratic/Full Length: "<<(double)(stop - start)/CLOCKS_PER_SEC <<endl;
			cout <<"Average time per insertion Quadratic/Full Length: "<<(double)(stop - start)/CLOCKS_PER_SEC/ DataArray.size()<< endl;

			for(int n = 0; n < DataArray.size(); n++)
				CollisionQuadraticHT += collision(DataArray.at(n), 3);
			cout<<"Total number of collision Quadratic/Full Length: "<<CollisionQuadraticHT<<endl;
			break;

		case 1:		//simple hash
			cout<<"\n****************Simple HashTable*****************"<<endl;

			cout << "Total insertion elapsed time in seconds SimpleHash: "
					<<(double)(stop - start)/CLOCKS_PER_SEC <<endl;
			cout <<"Average time per insertion SimpleHash: "<<(double)(stop - start)/CLOCKS_PER_SEC/ DataArray.size()<< endl;

			for(int n = 0; n < DataArray.size(); n++)
				CollisionSimple += collision(DataArray.at(n), 1);
			cout<<"Total number of collision SimpleHash: "<<CollisionSimple<<endl;
			break;
		
		case 2:		//pre-hash
			cout<<"\n****************Pre HashTable*****************"<<endl;

			cout << "Total insertion elapsed time in seconds PreHash: "
					<<(double)(stop - start)/CLOCKS_PER_SEC <<endl;
			cout <<"Average time per insertion PreHash: "<<(double)(stop - start)/CLOCKS_PER_SEC/ DataArray.size()<< endl;

			for(int n = 0; n < DataArray.size(); n++)
				CollisionPre += collision(DataArray.at(n), 2);
			cout<<"Total number of collision PreHash: "<<CollisionPre<<endl;
			break;
	 }
}

void HashTable_qp::findQuadraticHT(vector<string> QueryArray, int hashOption)
{
	clock_t k = clock();
	clock_t start = clock();
	do start = clock();
	while (start == k);

	switch(hashOption)
	{
		case 0:
		case 3:
			for(int n = 0; n < QueryArray.size(); n++)
				find(QueryArray.at(n), 3);
			break;
		case 1:
			for(int n = 0; n < QueryArray.size(); n++)
				find(QueryArray.at(n), 1);
			break;
		case 2:
			for(int n = 0; n < QueryArray.size(); n++)
				find(QueryArray.at(n), 2);
			break;
	}

	clock_t stop = clock();

	 switch(hashOption)
	  {
		case 0:
			cout << "\nTotal search elapsed time in seconds Quadratic/Full Length: "
					<<(double)(stop - start)/CLOCKS_PER_SEC <<endl;
			cout <<"Average time per search Quadratic/Full Length: "<<(double)(stop - start)/CLOCKS_PER_SEC/ QueryArray.size()<< endl;
			break;

		case 1:		//simple hash
			cout << "\nTotal search elapsed time in seconds SimpleHash: "
					<<(double)(stop - start)/CLOCKS_PER_SEC <<endl;
			cout <<"Average time per search SimpleHash: "<<(double)(stop - start)/CLOCKS_PER_SEC/ QueryArray.size()<< endl;
			break;

		case 2:		//pre-hash
			cout << "\nTotal search elapsed time in seconds PreHash: "
					<<(double)(stop - start)/CLOCKS_PER_SEC <<endl;
			cout <<"Average time per search PreHash: "<<(double)(stop - start)/CLOCKS_PER_SEC/ QueryArray.size()<< endl;
			break;

		case 3:		//full length hash
			cout << "\nTotal search elapsed time in seconds Full Length Hash: "
					<<(double)(stop - start)/CLOCKS_PER_SEC <<endl;
			cout <<"Average time per search Full Length Hash: "<<(double)(stop - start)/CLOCKS_PER_SEC/ QueryArray.size()<< endl;
			break;
	  }
}
///********************************************/
//
//int HashTable_qp::findPosUsingSimpleHash( const string & x ) const
//{
//      int collisionNum = 0;
//      int currentPos = simpleHash( x, array.size( ) );
//
//      while( array[ currentPos ].info != EMPTY &&
//           array[ currentPos ].element != x )
//    {
//          currentPos += 2 * ++collisionNum - 1;  // Compute ith probe
//          if( currentPos >= array.size( ) )
//              currentPos -= array.size( );
//    }
//
//      return currentPos;
//}
//
//int HashTable_qp::collisionUsingSimpleHash( const string & x ) 
//{
//      int collisionNum = 0;
//      int currentPos = simpleHash( x, array.size( ) );
//
//      while( array[ currentPos ].info != EMPTY &&
//           array[ currentPos ].element != x )
//    {
//          currentPos += 2 * ++collisionNum - 1;  // Compute ith probe
//          if( currentPos >= array.size( ) )
//              currentPos -= array.size( );
//    }
//
//      return collisionNum;
//}
//
//const string & HashTable_qp::findUsingSimpleHash( const string & x ) const
//{
//    int currentPos = findPosUsingSimpleHash( x );
//    if( isActive( currentPos ) )
//        return array[ currentPos ].element;
//    else
//        return ITEM_NOT_FOUND;
//}
//
//void HashTable_qp::insertUsingSimpleHash( const string & x )
//{
//        // Insert x as active
//    int currentPos = findPosUsingSimpleHash( x );
//    if( isActive( currentPos ) )
//        return;
//    array[ currentPos ] = HashEntry( x, ACTIVE );
//
//        // Rehash; see Section 5.5
//    if( ++currentSize > array.size( ) / 2 )
//        rehashUsingSimpleHash( );
//}
//
//void HashTable_qp::rehashUsingSimpleHash( )
//{
//    vector<HashEntry> oldArray = array;
//
//        // Create new double-sized, empty table
//    array.resize( nextPrime( 2 * oldArray.size( ) ) );
//    for( int j = 0; j < array.size( ); j++ )
//        array[ j ].info = EMPTY;
//
//        // Copy table over
//    currentSize = 0;
//    for( int i = 0; i < oldArray.size( ); i++ )
//        if( oldArray[ i ].info == ACTIVE )
//            insertUsingSimpleHash( oldArray[ i ].element );
//}
///***********************************************/
//
//int HashTable_qp::findPosUsingPreHash( const string & x ) const
//{
//      int collisionNum = 0;
//      int currentPos = preHash( x, array.size( ) );
//
//      while( array[ currentPos ].info != EMPTY &&
//           array[ currentPos ].element != x )
//    {
//          currentPos += 2 * ++collisionNum - 1;  // Compute ith probe
//          if( currentPos >= array.size( ) )
//              currentPos -= array.size( );
//    }
//
//      return currentPos;
//}
//
//const string & HashTable_qp::findUsingPreHash( const string & x ) const
//{
//    int currentPos = findPosUsingPreHash( x );
//    if( isActive( currentPos ) )
//        return array[ currentPos ].element;
//    else
//        return ITEM_NOT_FOUND;
//}
//
//int HashTable_qp::collisionUsingPreHash( const string & x ) 
//{
//      int collisionNum = 0;
//      int currentPos = preHash( x, array.size( ) );
//
//      while( array[ currentPos ].info != EMPTY &&
//           array[ currentPos ].element != x )
//    {
//          currentPos += 2 * ++collisionNum - 1;  // Compute ith probe
//          if( currentPos >= array.size( ) )
//              currentPos -= array.size( );
//    }
//
//      return collisionNum;
//}
//
//void HashTable_qp::insertUsingPreHash( const string & x )
//{
//        // Insert x as active
//    int currentPos = findPosUsingPreHash( x );
//    if( isActive( currentPos ) )
//        return;
//    array[ currentPos ] = HashEntry( x, ACTIVE );
//
//        // Rehash; see Section 5.5
//    if( ++currentSize > array.size( ) / 2 )
//        rehashUsingPreHash( );
//}
//
//void HashTable_qp::rehashUsingPreHash( )
//{
//    vector<HashEntry> oldArray = array;
//
//        // Create new double-sized, empty table
//    array.resize( nextPrime( 2 * oldArray.size( ) ) );
//    for( int j = 0; j < array.size( ); j++ )
//        array[ j ].info = EMPTY;
//
//        // Copy table over
//    currentSize = 0;
//    for( int i = 0; i < oldArray.size( ); i++ )
//        if( oldArray[ i ].info == ACTIVE )
//            insertUsingPreHash( oldArray[ i ].element );
//}