#include<iostream>
using namespace std;

int main(void)
{
	long long nArray[100] = { 1,1,1,2, };

	int nTry;
	cin >> nTry;
	while (nTry--)
	{
		int nInput;
		long long nOutput;
		cin >> nInput;

			for (int i = 4; i < nInput; i++) 
			{
				nArray[i] = nArray[i - 2] + nArray[i - 3];
			}

		nOutput = nArray[nInput - 1];
		cout << nOutput << endl;
	}
	return 0;
}