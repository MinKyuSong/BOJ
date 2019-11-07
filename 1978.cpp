#include<iostream>
using namespace std;

bool isPrime(int N)
{
	if (N < 2)
		return false;

	for (int i = 2; i*i <= N; i++)
	{
		if (N%i == 0)
			return false;
	}
	return true;
}

int main(void)
{
	int nTry, nResult = 0;
	cin >> nTry;

	while (nTry--)
	{
		int nInput;

		cin >> nInput;

		if (isPrime(nInput))
			nResult++;
	}

	cout << nResult << endl;

	return 0;
}