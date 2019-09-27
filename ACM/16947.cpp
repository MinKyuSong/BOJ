#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
int dist[3001];
int check[3001];
vector<int> vBranch;

int DFS(int node, int prev, const vector<vector<int>>& vGraph)
{
	if (check[node] == 1) return node;
	check[node] = 1;
	for (int next : vGraph[node])
	{
		if (next == prev)
			continue;
		int nResult = DFS(next, node, vGraph);
		if (nResult == -2) return -2;
		if (nResult > 0)
		{
			check[node] = 2;
			if (node == nResult) return -2;
			else return nResult;
		}
	}
	return -1;
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	vector<vector<int>> vGraph(N+1);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		vGraph[a].push_back(b);
		vGraph[b].push_back(a);
	}
	DFS(1, -1, vGraph);
	queue<int> qSearch;
	for (int i = 1; i <= N; i++)
	{
		if (check[i] == 2)
		{
			dist[i] = 0;
			qSearch.push(i);
		}
		else
		{
			dist[i] = -1;
		}
	}
	while (!qSearch.empty())
	{
		int node = qSearch.front();
		qSearch.pop();
		for (int next : vGraph[node])
		{
			if (dist[next] == -1)
			{
				qSearch.push(next);
				dist[next] = dist[node] + 1;
			}
		}
	}
	for (int i = 1; i <= N; i++)
		cout << dist[i] << " ";
	cout << endl;
	return 0;
}