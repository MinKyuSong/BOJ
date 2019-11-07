#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	vector<long long> vNums(N);

	for (int i = 0; i < N; i++)
		cin >> vNums[i];

	sort(vNums.begin(), vNums.end());

	int nMax(1), nCount(1);
	long long nResult(vNums[0]);
	for (int i = 1; i < N; i++)
	{
		if (vNums[i - 1] == vNums[i])
		{
			nCount++;
		}
		else
		{
			nCount = 1;
		}

		if (nCount > nMax)
		{
			nMax = nCount;
			nResult = vNums[i];
		}
	}

	cout << nResult << '\n';

	return 0;
}