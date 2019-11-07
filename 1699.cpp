#include<iostream>
using namespace std;

int main(void)
{
	int nInput;
	cin >> nInput;

	long long *pnData = new long long[nInput+1];

	for (int i = 1; i <= nInput; i++)
	{
		pnData[i] = i;
		for (int j = 1; j*j <= i; j++)
		{
			if (pnData[i-j*j] + 1 < pnData[i])
				pnData[i] = pnData[i-j*j] + 1;
		}
	}

	cout << pnData[nInput] << endl;

	delete[] pnData;
	return 0;
}