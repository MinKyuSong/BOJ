#include<iostream>
using namespace std;

long long gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return (long long)a;
}

int main(void)
{
	int nTry;
	cin >> nTry;
	while (nTry--)
	{
		long long g = 0;
		int nInput;
		cin >> nInput;

		int *nArray = new int[nInput];
		for (int i = 0; i < nInput; i++)
			cin >> nArray[i];

		for (int i = 0; i < nInput-1; i++)
			for (int j = i+1; j < nInput; j++)
				g += gcd(nArray[i], nArray[j]);
		
		cout << g << endl;

		delete[] nArray;
	}

	return 0;
}