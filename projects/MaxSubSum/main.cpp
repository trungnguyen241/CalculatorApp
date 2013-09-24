#include "MaxSum.h"

int main(void)
{
	int i = 0, arraySize =0;
	int k =0;
	MaxSum sum;
	int ans = 0;

	do{

	cout << "\nPlease input the size (8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192): " << endl;
	cin >> i;
	
	for (int j = 0; j < 10; j++){
		cout<<"---File number "<< j + 1<<"---\n";
		sum.load (i, j);
	}
	cout<<"Do you want to continue? <1 for yes>"<<endl;
	cin>> ans;

	}while(ans == 1);

	return 0;
}