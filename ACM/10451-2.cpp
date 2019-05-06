#include<iostream>
#include<vector>
using namespace std;

int nGraph[1001];
int nCheck[1001];

void dfs(int root, int nCount)
{
	nCheck[root] = nCount;
	if (nCheck[nGraph[root]] == 0)
		dfs(nGraph[root], nCount);
	return;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int nTry;
	cin >> nTry;
	while (nTry--)
	{
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> nGraph[i];
			nCheck[i] = 0;
		}

		int nCount = 0;
		for (int i = 1; i <= N; i++)
			if (nCheck[i] == 0)
				dfs(i, ++nCount);
		cout << nCount << endl;
	}
	return 0;
}