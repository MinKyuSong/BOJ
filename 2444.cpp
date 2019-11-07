#include<iostream>
#include<stdlib.h>
using namespace std;

int main(void)
{
	int nInput;

	cin >> nInput;

	for (int i = 1; i <= 2 * nInput - 1; i++)
	{
		for (int j = abs(nInput - i); j > 0; j--)
		{
			cout << " ";
		}
		if (i <= nInput)
		{
			for (int k = 2 * i - 1; k > 0; k--)
			{
				cout << "*";
			}
			cout << endl;
		}
		else
		{
			for (int k = 4 * nInput - 2 * i - 1; k > 0; k--)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	return 0;
}
