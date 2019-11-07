#include<iostream>

using namespace std;
static long long nCounts[1001][10];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < 10; i++)
		nCounts[1][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		nCounts[i][0] = 1;
		for (int j = 1; j <= 9; j++)
			nCounts[i][j] = (nCounts[i][j - 1] + nCounts[i - 1][j]) % 10007;
	}

	long long nResult = 0;
	for (int i = 0; i < 10; i++)
	{
		nResult = nResult + nCounts[N][i];
	}

	cout << nResult % 10007 << endl;
	return 0;
}