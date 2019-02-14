#include<iostream>

using namespace std;

int main(void)
{
	int nInput;
	long long nResult = 0;
	long long arrSteps[11][101];

	for (int i = 0; i < 101; i++)
	{
		arrSteps[10][i] = 0;
	}
	arrSteps[0][0] = 0; arrSteps[0][1] = 0;
	for (int i = 1; i < 10; i++)
	{
		arrSteps[i][0] = 0;
		arrSteps[i][1] = 1;
	}

	cin >> nInput;

	for (int i = 2; i <= nInput; i++)
	{
		arrSteps[0][i] = arrSteps[1][i - 1];
		for (int j = 1; j < 10; j++)
		{
			arrSteps[j][i] = (arrSteps[j - 1][i - 1] +
				arrSteps[j + 1][i - 1])% 1000000000;
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		nResult += arrSteps[i][nInput];
	}

	cout << nResult%1000000000 << endl;

	return 0;
}