#include<iostream>
using namespace std;

int nGraph[250000];

int mypow(int digit, int pow)
{
	int nResult = 1;
	for (int i = 0; i < pow; i++)
		nResult *= digit;
	return nResult;
}
int mynext(int now, int pow)
{
	int nResult = 0;
	int nTemp(now);
	while (nTemp > 0)
	{
		nResult += mypow(nTemp%10, pow);
		nTemp /= 10;
	}
	return nResult;
}
int dfs(int now, int pow, int count)
{
	if (nGraph[now] != 0)
		return nGraph[now] - 1;
	nGraph[now] = count;
	return dfs(mynext(now, pow), pow, count + 1);
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int A, P, nResult;
	cin >> A >> P;
	for (int i = 0; i < 250000; i++)
		nGraph[i] = 0;
	
	nResult = dfs(A, P,1);
	cout << nResult << endl;

	return 0;
}