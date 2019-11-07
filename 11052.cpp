#include<iostream>

using namespace std;

int getMax(int *arrPrice, int *arrResult, int &n)
{
	int nResult = 0;

	for (int i = 1; i <= n; i++)
	{
		if (nResult < (arrResult[n - i] + arrPrice[i]))
			nResult = arrResult[n - i] + arrPrice[i];
	}
	return nResult;
}

int main(void)
{
	int nInput;
	cin >> nInput;

	int *arrPrice = new int[nInput+1];
	int *arrResult = new int[nInput+1];

	arrPrice[0] = 0;
	for (int i = 1; i <= nInput; i++)
		cin >> arrPrice[i];

	arrResult[0] = 0;
	for (int i = 1; i <= nInput; i++)
		arrResult[i] = getMax(arrPrice, arrResult, i);

	cout << arrResult[nInput];

	delete[] arrPrice;
	delete[] arrResult;
	return 0;
}