#include<iostream>

using namespace std;

int N;
int nArr[1001];
int nArrD[1001];

int main(void) 
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> nArr[i];

	nArr[0] = nArrD[0] = 0;
	nArrD[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		int nTempMax = 0;
		for (int j = 1; j < i; j++)
			if (nTempMax<nArrD[j] && nArr[j]>nArr[i])
				nTempMax = nArrD[j];
		nArrD[i] = nTempMax + 1;
	}

	int nResult = 0;
	for (int i = 0; i <= N; i++)
		if (nResult < nArrD[i])
			nResult = nArrD[i];

	cout << nResult << endl;

	return 0;
}