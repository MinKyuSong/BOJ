#include<iostream>
using namespace std;

int main(void)
{
	int nCount;
	cin >> nCount;

	int *arrPoints = new int[nCount + 2];
	int *arrDS1 = new int[nCount + 2];
	int *arrDS2 = new int[nCount + 2];

	arrPoints[0] = arrDS1[0] =arrDS2[0]= 0;
	arrPoints[nCount+1] = arrDS1[nCount+1] = arrDS2[nCount+1] = 0;

	for (int i = 1; i < nCount+1; i++)
	{
		cin >> arrPoints[i];
	}

	// ascending
	for (int i = 1; i < nCount + 1; i++)
	{
		int nTemp = 0;
		for (int j = i - 1; j > -1; j--)
		{
			if ((arrPoints[j] < arrPoints[i]) && (arrDS1[j] > nTemp))
			{
				nTemp = arrDS1[j];
			}
		}
		arrDS1[i] = nTemp + 1;
	}

	//descending
	for (int i = nCount; i >0; i--)
	{
		int nTemp = 0;
		for (int j = i + 1; j < nCount+2; j++)
		{
			if ((arrPoints[j] < arrPoints[i]) && (arrDS2[j] > nTemp))
			{
				nTemp = arrDS2[j];
			}
		}
		arrDS2[i] = nTemp + 1;
	}

	int nResult = arrDS1[0]+arrDS2[0];
	for (int i = 1; i < nCount + 1; i++)
	{
		if (nResult < arrDS1[i]+arrDS2[i])
			nResult = arrDS1[i]+arrDS2[i];
	}

	cout << nResult-1 << endl;

	delete[] arrPoints;
	delete[] arrDS1;
	delete[] arrDS2;

	return 0;
}