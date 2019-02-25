#include<iostream>
using namespace std;

int main(void)
{
	int nInput;
	cin >> nInput;

	int *pnSolution = new int [nInput+1];

	pnSolution[0] = 1; pnSolution[1] = 0;

	for (int i = 2; i <= nInput; i++)
	{
		pnSolution[i] = 3 * pnSolution[i - 2];
		for (int j = i - 4; j >= 0; j = j - 2)
		{
			pnSolution[i] += (2 * pnSolution[j]);
		}
	}

	cout << pnSolution[nInput] << endl;

	delete[] pnSolution;

	return 0;
}