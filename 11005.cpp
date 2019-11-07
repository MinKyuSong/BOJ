#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int N, B;
	string szTemp, szResult;

	cin >> N >> B;
	
	while (N >= B)
	{
		char nTemp = N % B;
		N /= B;
		if (nTemp > 9)
			nTemp = nTemp - 10 + 'A';
		else
			nTemp += '0';

		szTemp.push_back(nTemp);
	}
	if (N > 9)
		N = N - 10 + 'A';
	else
		N += '0';
	szTemp.push_back(char(N));

	for (int i = szTemp.length() - 1; i > -1; i--)
		cout << szTemp[i];
	cout << endl;

	return 0;
}