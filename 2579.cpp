#include<iostream>
using namespace std;

long long GetMax(long long a, long long b)
{
	long long nResult = a;
	if (nResult < b)
		nResult = b;
	
	return nResult;
}

int main(void)
{
	int nCount;
	cin >> nCount;

	int *pnStairs = new int[nCount + 1];
	long long *pnScores = new long long[nCount + 1];

	pnStairs[0] = 0; pnScores[0] = 0;
	for (int i = 1; i < nCount + 1; i++)
		cin >> pnStairs[i];

	if (nCount >= 1) pnScores[1] = pnStairs[1];
	if (nCount >= 2) pnScores[2] = pnStairs[2] + pnScores[1];
	for (int i = 3; i < nCount + 1; i++)
	{
		pnScores[i] = GetMax((pnScores[i - 2]), (pnScores[i - 3] + pnStairs[i - 1])) + pnStairs[i];
	}

	cout << pnScores[nCount] << endl;

	delete[] pnStairs;
	delete[] pnScores;
	return 0;
}