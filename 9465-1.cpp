#include<iostream>

using namespace std;
int nArrPoints[2][100001];
long long nSums[2][100001];
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			cin >> nArrPoints[0][i];
		}
		for (int i = 1; i <= N; i++)
		{
			cin >> nArrPoints[1][i];
		}

		nSums[0][0] = 0; nSums[1][0] = 0;
		nSums[0][1] = nArrPoints[0][1];
		nSums[1][1] = nArrPoints[1][1];
		for (int i = 2; i <= N; i++)
		{
			long long temp = (nSums[0][i - 2] > nSums[1][i - 2]) ? nSums[0][i - 2] : nSums[1][i - 2];
			nSums[0][i] = nArrPoints[0][i] + (temp > nSums[1][i - 1] ? temp: nSums[1][i - 1]);
			nSums[1][i] = nArrPoints[1][i] + (temp > nSums[0][i - 1] ? temp : nSums[0][i - 1]);
		}

		long long nResult = (nSums[0][N] > nSums[1][N]) ? nSums[0][N] : nSums[1][N];
		cout<< nResult <<endl;
	}

	return 0;
}