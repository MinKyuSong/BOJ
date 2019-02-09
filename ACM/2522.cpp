#include<iostream>
#include<stdlib.h>

using namespace std;

int main(void)
{
	int nInput;
	cin >> nInput;

	for(int i=1;i<=2*nInput-1;i++)
	{
		int j = 1;
		for (; j <= abs(nInput - i); j++)
			cout << " ";
		for (; j <= nInput; j++)
			cout << "*";
		cout << endl;
	}
	return 0;
}