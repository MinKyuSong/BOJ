#include<iostream>

using namespace std;

int N;
int nArr[1001];
int nArrSums[1001];
int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> nArr[i];

	nArrSums[0] = nArr[0] = 0;
	nArrSums[1] = nArr[1];

	for (int i = 2; i <= N; i++)
	{
		int nTempMax = 0;
		for (int j = 0; j < i; j++)
		{
			if (nArrSums[j] > nTempMax && nArr[i] > nArr[j])
				nTempMax = nArrSums[j];
		}
		nArrSums[i] = nTempMax + nArr[i];
	}

	int nResult = 0;
	for (int i = 0; i <= N; i++)
		if (nResult < nArrSums[i])
			nResult = nArrSums[i];

	cout << nResult << endl;

	return 0;
}