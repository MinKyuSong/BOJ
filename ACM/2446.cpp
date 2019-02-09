#include<iostream>
#include<stdlib.h>
using namespace std;

int main(void)
{
	int nInput;
	cin >> nInput;

	for (int i = 1; i < 2 * nInput; i++)
	{
		if (i < nInput)
		{
			for (int j = 1; j < i; j++)
				cout << " ";
			for (int j = 1; j <= 2 * (nInput - i) + 1; j++)
				cout << "*";
		}
		else if (i == nInput)
		{
			for (int j = 1; j < nInput; j++)
				cout << " ";
			cout << "*";
		}
		else
		{
			for (int j = 1; j <= 2*nInput-1-i; j++)
				cout << " ";
			for (int j = 1; j <= 2 * (i - nInput) + 1; j++)
				cout << "*";
		}
		cout << endl;
	}

	return 0;
}