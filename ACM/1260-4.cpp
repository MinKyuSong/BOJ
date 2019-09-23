#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

bool bcheck[1001];
bool dcheck[1001];

void DFS(int node, const vector<vector<int>>& vGraph)
{
	cout << node << " ";
	dcheck[node] = true;
	for (int next : vGraph[node])
	{
		if (!dcheck[next])
			DFS(next, vGraph);
	}
	return;
}

void BFS(int node, const vector<vector<int>>& vGraph)
{
	queue<int> qSearch;
	
	bcheck[node] = true;
	cout << node << " ";
	qSearch.push(node);

	while (!qSearch.empty())
	{
		int now = qSearch.front();
		qSearch.pop();
		for (int next : vGraph[now])
		{
			if (!bcheck[next])
			{
				bcheck[next] = true;
				cout << next << " ";
				qSearch.push(next);
			}
		}
	}
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int N, M, V;
	cin >> N >> M >> V;

	vector<vector<int>> vGraph(N+1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vGraph[a].push_back(b);
		vGraph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(vGraph[i].begin(), vGraph[i].end());

	DFS(V, vGraph);
	cout << endl;
	BFS(V, vGraph);
	cout << endl;

	return 0;
}