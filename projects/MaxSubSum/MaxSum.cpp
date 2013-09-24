#include "MaxSum.h"


int MaxSum::maxSubSum1 (const vector <int> & a)
{
	int maxSum = 0;

	for (int i = 0; i < a.size(); i ++){
		for (int j = i; j < a.size(); j ++) 
		{
			int thisSum = 0;

			for (int k = i; k <= j; k++){
				thisSum += a[k];
			}
			
			if (thisSum > maxSum){
				maxSum = thisSum;
				//cout<<"MaxSum inside for loop = "<<maxSum<<endl;
			}
		}
	}
		return maxSum;
}


int MaxSum::maxSubSum2 (const vector <int> & a)
{
	int maxSum = 0;

	for (int i = 0; i < a.size(); i++) 
	{
		int thisSum = 0;
		for(int j = i; j < a.size(); j++)
		{
			thisSum += a[j];

			if(thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

int MaxSum::max3 (int left, int right, int middle)
{
	int max = left;

	if((right > left) && (right > middle))
		max = right;
	else if ((middle > left) && (middle > right))
		max = middle;

	return max;
}
int MaxSum::maxSubRec (const vector<int> & a, int left, int right)
{
	if (left == right)
		if( a[left] > 0)
			return a[left];
		else
			return 0;

	int center = (left + right) /2;
	int maxLeftSum = maxSubRec(a, left, center);
	int maxRightSum = maxSubRec(a, center +1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for(int i = center; i >= left; i--){
		leftBorderSum += a[i];
		if(leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;;
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for(int j = center + 1; j <= right; j++){
		rightBorderSum += a[j];
		if(rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int MaxSum::maxSubSum3 (const vector<int> & a)
{
	return maxSubRec(a, 0, a.size() - 1);
}

int MaxSum::maxSubSum4 (const vector<int> & a)
{
	int maxSum = 0, thisSum = 0;

	for(int j = 0; j < a.size(); j ++)
	{
		thisSum += a[j];

		if(thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}
	return maxSum;
}

void MaxSum::load(int size, int input_size)
{	
	MaxSum maxSumAA;

	vector<int> arrayNumber1(size);
	string filename, tempString;
	ostringstream ss;
	ifstream infile;

	filename = "input_";
	int index = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

	ss << filename << size <<"_" << input_size <<".txt";
	infile.open (ss.str().c_str());
		
	while (!infile.eof())
	{	
		
		getline(infile, tempString, '-');
		tempString.erase(std::remove(tempString.begin(), tempString.end(), '\n'), tempString.end());

		int tempInt = atoi(tempString.c_str());
		//cout<<"tempInt = "<<tempInt<<endl;

		arrayNumber1[index] = tempInt;
		index++;
	}
	arrayNumber1 [index + 1] = '/0';

/*Algorithms 1----------------------------------------------*/
	clock_t k1 = clock();
	clock_t  start1 = clock();
	do start1 = clock();
	while (start1 == k1);

	sum1 = maxSumAA.maxSubSum1(arrayNumber1);
	cout << "MaxSum1:" << sum1 << endl;

	clock_t end1 =clock();
	printf ("Elapsed time in milliconds: %.2f\n\n", (double)(end1 - start1));//*(double)CLOCKS_PER_SEC );

/*Algorithms 2----------------------------------------------*/
	clock_t k2 = clock();
	clock_t  start2 = clock();
	do start2 = clock();
	while (start2 == k2);

	sum2 = maxSumAA.maxSubSum2(arrayNumber1);
	cout << "MaxSum2:" << sum2 << endl;

	clock_t end2 =clock();
	printf ("Elapsed time in milliseconds: %.2f\n\n", (double)(end2 - start2));

/*Algorithms 3----------------------------------------------*/
	clock_t k3 = clock();
	clock_t  start3 = clock();
	do start3 = clock();
	while (start3 == k3);

	sum3 = maxSumAA.maxSubSum3(arrayNumber1);
	cout << "MaxSum3:" << sum3 << endl;

	clock_t end3 =clock();
	printf ("Elapsed time in milliseconds: %.2f\n\n", (double)(end3 - start3));

/*Algorithms 4----------------------------------------------*/
	clock_t k4 = clock();
	clock_t  start4 = clock();
	do start4 = clock();
	while (start4 == k4);

	sum4 = maxSumAA.maxSubSum4(arrayNumber1);
	cout << "MaxSum4:" << sum4 << endl;
	
	clock_t end4 =clock();
	printf ("Elapsed time in milliseconds: %.2f\n\n", (double)(end4 - start4));

	ss.str("");
}