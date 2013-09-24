//#include <iostream>
//#include "Chaining.h"
//#include "QuadraticProbing.h"
//
//using namespace std;
//
//int main( )
//{
//    string ITEM_NOT_FOUND = "ITEM_NOT_FOUND";
//	cout << "Testing chaining...\n";
//    HashTable_chaining Hc( ITEM_NOT_FOUND, 101 );
//
//	Hc.insert("word1");
//	Hc.insert("word2");
//	Hc.insert("word3");
//	Hc.insert("hello1");
//	Hc.insert("hello2");
//
//	cout << "Searching for word3: "  << Hc.find("word3") << endl;
//	cout << "Searching for hello2: "  << Hc.find("hello2") << endl;
//	cout << "Searching for missingword: "  << Hc.find("missingword") << endl;
//
//	Hc.remove("hello2");
//	cout << "Searching for hello2: "  << Hc.find("hello2") << endl;
//
//	cout << "Testing quadratic probing...\n";
//    HashTable_chaining Hq( ITEM_NOT_FOUND, 101 );
//
//	Hq.insert("word1");
//	Hq.insert("word2");
//	Hq.insert("word3");
//	Hq.insert("hello1");
//	Hq.insert("hello2");
//
//	cout << "Searching for word3: "  << Hq.find("word3") << endl;
//	cout << "Searching for hello2: "  << Hq.find("hello2") << endl;
//	cout << "Searching for missingword: "  << Hq.find("missingword") << endl;
//
//	Hq.remove("hello2");
//	cout << "Searching for hello2: "  << Hq.find("hello2") << endl;
//
//    return 0;
//}
