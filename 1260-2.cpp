#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

bool check[1001];
vector<int> graph[1001];

void dfs(int node)
{
	check[node] = true;
	cout << node << ' ';
	for (unsigned int i = 0; i < graph[node].size(); i++)
	{
		if (check[graph[node][i]] == false)
		{
			dfs(graph[node][i]);
		}
	}
	return;
}

void bfs(int node)
{
	queue<int> qSearch;
	check[node] = true;
	qSearch.push(node);
	while (!qSearch.empty())
	{
		int nTemp;
		nTemp = qSearch.front(); qSearch.pop();
		cout << nTemp << ' ';

		for (unsigned int i = 0; i < graph[nTemp].size(); i++)
		{
			if (check[graph[nTemp][i]] == false)
			{
				qSearch.push(graph[nTemp][i]);
				check[graph[nTemp][i]] = true;
			}
		}
	}
	return;
}

int main(void)
{
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int v, u;
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	for (int i = 0; i < 1001; i++)
		check[i] = false;
	dfs(V);
	cout << '\n';
	for (int i = 0; i < 1001; i++)
		check[i] = false;
	bfs(V);
	cout << '\n';
	return 0;
}