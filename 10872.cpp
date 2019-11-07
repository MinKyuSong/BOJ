#include<iostream>
using namespace std;

int main(void)
{
	int nInput, nResult = 1;
	cin >> nInput;

	for (int i = 1; i <= nInput; i++)
		nResult *= i;

	cout << nResult << endl;

	return 0;
}