#include<iostream>

using namespace std;

int nGraph[100001];
int nCount[100001];
int nGroup[100001];

int dfs(int root, int grp, int cnt)
{
	if (nGroup[root] != 0 && nGroup[root] != grp)
		return 0;
	if (nGroup[root] == grp)
		return cnt-nCount[root];

	nCount[root] = cnt;
	nGroup[root] = grp;
	return dfs(nGraph[root], grp, cnt + 1);
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		
		for (int i = 1; i <= n; i++)
		{
			cin >> nGraph[i];
			nGroup[i] = 0;
			nCount[i] = 0;
		}

		int nResult = 0;
		int ngrp = 1;
		for (int i = 1; i <= n; i++)
			if (nGroup[i] == 0)
				nResult += dfs(i, ngrp++, 1);
		cout << n-nResult<<endl;
	}
	return 0;
}