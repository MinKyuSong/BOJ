#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int *pnSum = new int[N];

	vector<int>vTime(N);
	for (int i = 0; i < N; i++)
		cin >> vTime[i];
	sort(vTime.begin(), vTime.end());


	pnSum[0] = vTime[0];
	for (int i = 1; i < N; i++)
	{
		pnSum[i] = vTime[i] + pnSum[i - 1];
	}

	int nResult = 0;
	for (int i = 0; i < N; i++)
		nResult += pnSum[i];
	cout << nResult << endl;

	delete[] pnSum;
	return 0;
}