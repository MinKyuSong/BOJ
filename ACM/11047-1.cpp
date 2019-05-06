#include<iostream>

using namespace std;

int coins[10];

int main(void)
{
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}

	int nResult = 0, nRemainder = K;
	
	for (int i = N - 1; i > -1; i--)
	{
		nResult += (nRemainder / coins[i]);
		nRemainder = nRemainder % coins[i];
	}
	if (nRemainder)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << nResult << endl;
	return 0;
}