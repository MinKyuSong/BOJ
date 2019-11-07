#include<iostream>
using namespace std;

int pnCoins[10];

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N, nTotal, nResult=0;
	cin >> N >> nTotal;

	for (int i = 0; i < N; i++)
		cin >> pnCoins[i];

	for (int i = N - 1; i > -1 && nTotal > 0; i--)
	{
		nResult += (nTotal / pnCoins[i]);
		nTotal %= pnCoins[i];
	}

	cout << nResult << endl;

	return 0;
}