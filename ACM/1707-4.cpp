#include<iostream>
#include<vector>
using namespace std;

int check[20001];
bool DFS(const vector<vector<int>>& vGraph, int node, int group)
{
	bool res = true;
	check[node] = group;
	for (int next : vGraph[node])
	{
		
		if (check[next] == group)
			return false;
		if (check[next]==0)
		{
			res = DFS(vGraph, next, 3 - group);
		}
	}
	return res;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int K;
	cin >> K;
	while (K--)
	{
		int V, E;
		cin >> V >> E;
		vector<vector<int>> vGraph(V + 1);
		for (int i = 0; i <= V; i++)
			check[i] = 0;
		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			vGraph[a].push_back(b);
			vGraph[b].push_back(a);
		}

		bool result = true;
		for (int i = 1; i <= V; i++)
		{
			if (check[i] == 0)
			{
				result = DFS(vGraph, i, 1);
				if (result == false)
					break;
			}
		}
		if (result)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}