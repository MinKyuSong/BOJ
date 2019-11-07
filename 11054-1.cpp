#include<iostream>

using namespace std;

int N;
int nArr[1001];
int nArrI[1001];
int nArrD[1001];

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> nArr[i];

	nArr[0] = nArrI[0] = 0;
	nArrI[1] = 1; nArrD[N] = 1;

	for (int i = 2; i <= N; i++)
	{
		int nTempMax = 0;
		for (int j = 1; j < i; j++)
			if (nTempMax<nArrI[j] && nArr[j]<nArr[i])
				nTempMax = nArrI[j];
		nArrI[i] = nTempMax + 1;
	}
	for (int i = N - 1; i >= 1; i--)
	{
		int nTempMax = 0;
		for (int j = N; j > i; j--)
			if (nTempMax<nArrD[j] && nArr[j]<nArr[i])
				nTempMax = nArrD[j];
		nArrD[i] = nTempMax + 1;
	}

	int nResult = 0;
	for (int i = 0; i <= N; i++)
		if (nResult < nArrI[i]+nArrD[i])
			nResult = nArrI[i] + nArrD[i];

	cout << nResult-1 << endl;

	return 0;
}