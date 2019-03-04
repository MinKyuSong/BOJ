#include<iostream>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	long long **pnData = new long long* [k + 1];
	for (int i = 0; i < k + 1; i++)
		pnData[i] = new long long[n + 1];
	for (int i = 0; i < k + 1; i++)
		for (int j = 0; j < n + 1; j++)
			pnData[i][j] = 0;

	pnData[0][0] = 1LL;
	for (int i = 1; i < k + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				pnData[i][j] += pnData[i - 1][j - l];
				pnData[i][j] %= 1000000000;
			}
		}
	}

	cout << pnData[k][n] << endl;

	for (int i = 0; i < k + 1; i++)
		delete[] pnData[i];
	delete[] pnData;

	return 0;
}