#include<iostream>
using namespace std;

int n;
long long nArr[2][100001];

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nArr[0][i];

	nArr[1][0] = nArr[0][0];
	for (int i = 1; i < n; i++)
	{
		nArr[1][i] = (nArr[1][i - 1] + nArr[0][i]) > nArr[0][i] ?
			(nArr[1][i - 1] + nArr[0][i]) : nArr[0][i];
	}

	long long ans=nArr[1][0];
	for (int i = 0; i < n; i++)
	{
		if (nArr[1][i] > ans)
			ans = nArr[1][i];
	}
	cout << ans << endl;
	return 0;
}