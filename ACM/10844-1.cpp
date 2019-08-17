#include<iostream>

using namespace std;
static long long nCounts[101][10];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i < 10; i++)
		nCounts[1][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < 9; j++)
			nCounts[i][j] = (nCounts[i - 1][j - 1] + nCounts[i - 1][j + 1]) % 1000000000;
		nCounts[i][9] = nCounts[i - 1][8] % 1000000000; nCounts[i][0] = nCounts[i - 1][1] % 1000000000;
	}

	long long nResult = 0;
	for (int i = 0; i < 10; i++)
	{
		nResult = nResult + nCounts[N][i];
	}

	cout << nResult % 1000000000 << endl;
	return 0;
}