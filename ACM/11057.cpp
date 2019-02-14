#include<iostream>

using namespace std;

int sumSteps(int arrSteps[][10], int &rows, int &cols)
{
	int nResult = 0;
	for (int i = 0; i <= cols; i++)
		nResult += arrSteps[rows - 1][i];
	return nResult % 10007;
}

int main(void)
{
	int nInput, nResult=0;
	int arrSteps[1001][10];

	cin >> nInput;

	for (int i = 0; i < 10; i++)
	{
		arrSteps[1][i] = 1;
	}
	for (int i = 2; i <= nInput; i++)
	{
		arrSteps[i][0] = arrSteps[i - 1][0];
		for (int j = 1; j < 10; j++)
			arrSteps[i][j] = sumSteps(arrSteps,i,j);
	}

	for (int i = 0; i < 10; i++)
	{
		nResult += arrSteps[nInput][i];
	}
	cout << nResult % 10007 << endl;
	return 0;
}