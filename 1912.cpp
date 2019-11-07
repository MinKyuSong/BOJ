#include<iostream>
using namespace std;

int main(void)
{
	int nCount;
	cin >> nCount;

	int *pnInput = new int[nCount];
	long long *pnDS = new long long[nCount];

	for (int i = 0; i < nCount; i++)
	{
		cin >> pnInput[i];
	}

	pnDS[0] = pnInput[0];
	for (int i = 1; i < nCount; i++)
	{
		pnDS[i] = ((pnDS[i - 1] + pnInput[i]) > pnInput[i]) ? (pnDS[i - 1] + pnInput[i]) : pnInput[i];
	}

	long long nResult = pnDS[0];
	for (int i = 1; i < nCount; i++)
	{
		if (nResult < pnDS[i])
			nResult = pnDS[i];
	}
	cout << nResult << endl;

	delete[] pnInput;
	delete[] pnDS;

	return 0;
}