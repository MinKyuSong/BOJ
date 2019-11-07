#include<iostream>
#include<vector>

using namespace std;

vector<int> vGraph[20001];
int check[20001];

void dfs(int root, int group)
{
	check[root] = group;
	for (unsigned int i = 0; i < vGraph[root].size(); i++)
	{
		if (check[vGraph[root][i]] == 0)
			dfs(vGraph[root][i], 3 - group);
	}
	return;
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int nTry;
	cin >> nTry;
	while (nTry--)
	{
		int V, E;
		cin >> V >> E;
		
		for (int i = 0; i <= V; i++)
		{
			vGraph[i].clear();
			check[i] = 0;
		}
		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			vGraph[v].push_back(u);
			vGraph[u].push_back(v);
		}
		for (int i = 1; i <= V; i++)
			if (check[i] == 0)
				dfs(i, 1);

		bool bResult = true;
		for (int i = 1; i <= V; i++)
		{
			for (unsigned int j = 0; j < vGraph[i].size(); j++)
				if (check[vGraph[i][j]] == check[i])
				{
					bResult = false;
					break;
				}
			if (bResult == false)
				break;
		}
		if (bResult)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}