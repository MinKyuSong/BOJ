#include<iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	static int arrNums[10001];
	int nInput, nMax = 0;
	cin >> nInput;

	for (int i = 0; i < nInput; i++)
	{
		int nTemp;
		cin >> nTemp;
		if (nMax < nTemp)
			nMax = nTemp;
		arrNums[nTemp]++;
	}
	for (int i = 0; i <= nMax; i++)
	{
		if (arrNums[i] == 0) continue;
		for (int j = 0; j < arrNums[i]; j++)
			cout << i << '\n';
	}
	return 0;
}