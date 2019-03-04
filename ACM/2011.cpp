#include<iostream>
#include<cstring>
#define mod 1000000
using namespace std;

int main(void)
{
	char arrInput[5001];
	cin >> arrInput;

	int nLen = strlen(arrInput);
	int *pDS = new int[nLen+1];

	pDS[0] = 1;
	for (int i = 1; i <= nLen; i++)
		pDS[i] = 0;

	for (int i = 0, j=1; i < nLen; i++,j++)
	{
		int t1 = arrInput[i]-'0'; int t2 = 0;

		if(t1>0)
			pDS[j] = pDS[j - 1];
		
		if (i > 0)
			t2 = arrInput[i - 1] - '0';

		if (t1 == 0 && t2 == 0)
			break;

		if (t2 < 3 && t2 > 0 && i > 0)
		{
			int t3 = 10 * t2 + t1;
			if (t3 < 27)
				pDS[j] += pDS[j - 2];
		}
		pDS[j] %= mod;
	}

	cout << pDS[nLen] << endl;

	delete[] pDS;
	return 0;
}