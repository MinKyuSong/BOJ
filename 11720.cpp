#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
	int nDigits, sum = 0, nInput;
	cin >> nDigits;
	while (nDigits--)
	{
		scanf("%1d", &nInput);
		sum += nInput;
	}
	cout << sum << endl;
	return 0;
}