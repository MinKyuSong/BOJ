#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool check[1001];
void DFS(const int start, const vector<vector<int>> &vVertex)
{
	check[start] = true;
	cout << start << " ";
	for (int i = 0; i < vVertex[start].size(); i++)
	{
		if (check[vVertex[start][i]] == false)
			DFS(vVertex[start][i], vVertex);
	}
	return;
}
void BFS(const int start, const vector<vector<int>>& vVertex)
{
	queue<int> qSearch;
	qSearch.push(start);
	check[start] = true;
	
	while (!qSearch.empty())
	{
		int t = qSearch.front();
		qSearch.pop();
		cout << t << " ";
		for (int i = 0; i < vVertex[t].size(); i++)
		{
			if (check[vVertex[t][i]] == false)
			{
				check[vVertex[t][i]] = true;
				qSearch.push(vVertex[t][i]);
			}
		}

	}
}
int main(void)
{
	int V, E, S;
	cin >> V >> E >> S;
	
	vector<vector<int>> vVertex(V+1);
	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;
		vVertex[a].push_back(b);
		vVertex[b].push_back(a);
	}

	for (int i = 1; i <= V; i++)
		sort(vVertex[i].begin(), vVertex[i].end());

	DFS(S, vVertex);
	cout << endl;

	for (int i = 0; i <= V; i++)
		check[i] = false;
	BFS(S, vVertex);
	cout << endl;

	return 0;
}