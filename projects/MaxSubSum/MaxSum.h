#ifndef __MAXSUM_H__
#define __MAXSUM_H__

#include<ctime>
#include<iostream>
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

class MaxSum {

	public:
		//MaxSum();
		//MaxSum(vector<int> a);
		//~MaxSum();
		
		int maxSubSum1 (const vector<int> & a);

		int maxSubSum2 (const vector <int> & a);

		int max3 (int left, int right, int middle);
		int maxSubRec (const vector<int> & a, int left, int right);
		int maxSubSum3 (const vector<int> & a);

		int maxSubSum4 (const vector<int> & a);

		void load(int size, int input_size);

	public:
		vector<int> a;

};

#endif 