#include<iostream>

using namespace std;

int main(void)
{
	static int nArray[1001];

	int nInput;
	cin >> nInput;

	nArray[0] = 1; nArray[1] = 1;
	for (int i = 2; i <= nInput; i++)
	{
		nArray[i] = (nArray[i - 1] + nArray[i - 2])%10007;
	}

	cout << nArray[nInput] << endl;
	
	return 0;
}