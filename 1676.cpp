#include<iostream>
using namespace std;

int main(void)
{
	int nInput;
	long long nFiveCount = 0;

	cin >> nInput;

	for (int i = 1; i <= nInput; i++)
	{
		int nTemp = i;
		while (nTemp % 5 == 0)
		{
			nFiveCount++;
			nTemp /= 5;
		}
	}

	cout << nFiveCount << endl;

	return 0;
}