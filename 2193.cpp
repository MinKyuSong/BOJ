#include<iostream>

using namespace std;

int main(void)
{
	int nInput;
	long long arrCounts[91];

	cin >> nInput;

	arrCounts[0] = 0; arrCounts[1] = 1;
	for (int i = 2; i <= nInput; i++)
	{
		arrCounts[i] = arrCounts[i - 1] + arrCounts[i - 2];
	}

	cout << arrCounts[nInput] << endl;

	return 0;
}