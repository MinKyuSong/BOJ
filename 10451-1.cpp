#include<iostream>
using namespace std;

int group[1001];
int node[1001];

void dfs(int root, int cnt)
{
	if (group[root] != 0)
		return;
	group[root] = cnt;
	return dfs(node[root], cnt);
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	int nTry;
	cin >> nTry;

	while (nTry--)
	{
		int N, cnt = 0;
		
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			group[i] = 0;
			cin >> node[i];
		}
		for (int i = 1; i <= N; i++)
		{
			if (group[i] == 0)
				dfs(i, ++cnt);
		}
		cout << cnt << '\n';
	}

	return 0;
}