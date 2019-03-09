#include<iostream>
using namespace std;

int main(void)
{
	long long N, M;
	long long nTwoCount = 0, nFiveCount = 0;

	cin >> N >> M;

	for (long long i = 5; i <= N; i*=5)
	{
		nFiveCount += N / i;
	}
	for (long long i = 2; i <= N; i *= 2)
	{
		nTwoCount += N / i;
	}
	for (long long i = 5; i <= M; i *= 5)
	{
		nFiveCount -= M / i;
	}
	for (long long i = 2; i <= M; i *= 2)
	{
		nTwoCount -= M / i;
	}
	long long K = N - M;
	for (long long i = 5; i <= K; i *= 5)
	{
		nFiveCount -= K / i;
	}
	for (long long i = 2; i <= K; i *= 2)
	{
		nTwoCount -= K / i;
	}
	long long nResult = (nTwoCount < nFiveCount) ? nTwoCount : nFiveCount;
	cout << nResult << endl;

	return 0;
}