
#ifndef GLOBAL_FUNCTIONS_H_
#define GLOBAL_FUNCTIONS_H_

#include <vector>
#include <string>
#include<ctime>

using namespace std;


bool isPrime( int n );
int nextPrime( int n );
int hash( const string & key, int tableSize );
int hash( int key, int tableSize );
int simpleHash(const string & key, int tableSize);
int preHash(const string &key, int tableSize);

#endif
