#include<iostream>

using namespace std;

int GetMax(int a, int b, int c = -1)
{
	int nResult = a;
	if (nResult < b)
		nResult = b;
	if (nResult < c)
		nResult = c;
	return nResult;
}

int main(void)
{
	int nTry;
	cin >> nTry;

	while (nTry--)
	{
		int nLen;
		int *nStickers[2];
		int *nPoints[3];
		long long nResult = 0;

		cin >> nLen;

		nStickers[0] = new int[nLen+1];
		nStickers[1] = new int[nLen+1];
		nPoints[0] = new int[nLen + 1];
		nPoints[1] = new int[nLen + 1];
		nPoints[2] = new int[nLen + 1];

		nStickers[0][0] = nStickers[1][0] = 0;
		for (int i = 1; i <= nLen; i++)
		{
			cin >> nStickers[0][i];
		}
		for (int i = 1; i <= nLen; i++)
		{
			cin >> nStickers[1][i];
		}

		nPoints[0][0] = nPoints[1][0] = nPoints[2][0] = 0;
		for (int i = 1; i <= nLen; i++)
		{
			nPoints[0][i] = GetMax(nPoints[1][i - 1], nPoints[2][i - 1]) + nStickers[0][i];
			nPoints[1][i] = GetMax(nPoints[0][i - 1], nPoints[2][i - 1]) + nStickers[1][i];
			nPoints[2][i] = GetMax(nPoints[0][i - 1], nPoints[1][i - 1], nPoints[2][i - 1]);
		}

		nResult = GetMax(nPoints[0][nLen], nPoints[1][nLen], nPoints[2][nLen]);
		cout << nResult << endl;

		delete[] nStickers[0];
		delete[] nStickers[1];
		delete[] nPoints[0];
		delete[] nPoints[1];
		delete[] nPoints[2];
	}

	return 0;
}