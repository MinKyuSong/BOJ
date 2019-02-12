#include<iostream>

using namespace std;

int getMin(int &a, int &b, int &c)
{
	int nMin = a;
	if (nMin > b)
		nMin = b;
	if (nMin > c)
		nMin = c;

	return nMin;
}

int main(void)
{
	int nInput;
	cin >> nInput;

	int *nArray = new int[nInput+1];

	nArray[0] = -1; nArray[1] = 0;
	for (int i = 2; i <= nInput; i++)
	{
		int a=nInput+1, b=nInput+1;
		if (i % 3 == 0)
			a = nArray[i / 3];
		if (i % 2 == 0)
			b = nArray[i / 2];
		nArray[i] = getMin(a, b, nArray[i - 1]) + 1;
	}

	cout << nArray[nInput] << endl;

	return 0;
}