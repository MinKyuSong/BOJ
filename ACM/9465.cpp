#include<iostream>

using namespace std;

int main(void)
{
	int nTry;
	cin >> nTry;

	while (nTry--)
	{
		int nLen;
		int *nStickers[2];
		long long nResult = 0;

		cin >> nLen;
		nStickers[0] = new int[nLen+1];
		nStickers[1] = new int[nLen+1];

		nStickers[0][0] = nStickers[1][0] = 0;
		for (int i = 1; i <= nLen; i++)
		{
			cin >> nStickers[0][i];
		}
		for (int i = 1; i <= nLen; i++)
		{
			cin >> nStickers[1][i];
		}

		for (int i = 1; i < nLen; i++)
		{

		}

		delete[] nStickers[0];
		delete[] nStickers[1];
		cout << nResult << endl;
	}

	return 0;
}