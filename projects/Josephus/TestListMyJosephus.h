
#ifndef __TestListMyJosephus_H__
#define __TestListMyJosephus_H__

#include <iostream>
#include <list>
#include "Person.h"
#include "ListMyJosephus.h"

using namespace std;

class TestListMyJosephus {
	public:
		TestListMyJosephus();
		~TestListMyJosephus();

		void playGameList();

	public:
		ListMyJosephus *player; //player on the game
};

#endif;