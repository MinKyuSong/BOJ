#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(void)
{
	char *N = new char[33];
	int B, nResult = 0, nLen;
	
	cin >> N >> B;
	nLen = strlen(N);
	for (int i = 0; i < nLen; i++)
	{
		int nTemp;
		if (N[i] >= 'A')
			nTemp = N[i] - 'A' + 10;
		else
			nTemp = N[i] - '0';
		nResult += nTemp;
		if (i < nLen-1)
			nResult *= B;
	}

	cout << nResult << endl;

	return 0;
}