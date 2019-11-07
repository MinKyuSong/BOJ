#include<iostream>
using namespace std;

int main(void)
{
	int nCount;
	cin >> nCount;

	int *arrPoints = new int[nCount + 1];
	int *arrDS = new int[nCount + 1];

	arrPoints[0] = arrDS[0] = 0;

	for (int i = 1; i < nCount + 1; i++)
	{
		cin >> arrPoints[i];
	}

	for (int i = 1; i < nCount + 1; i++)
	{
		int nTemp = 0;
		for (int j = i - 1; j > -1; j--)
		{
			if ((arrPoints[j]<arrPoints[i])&&(arrDS[j]>nTemp))
			{
				nTemp = arrDS[j];
			}
		}
		arrDS[i] = nTemp + 1;
	}

	int nResult = arrDS[0];
	for (int i = 1; i < nCount + 1; i++)
	{
		if (nResult < arrDS[i])
			nResult = arrDS[i];
	}

	cout << nResult << endl;

	delete[] arrPoints;
	delete[] arrDS;

	return 0;
}