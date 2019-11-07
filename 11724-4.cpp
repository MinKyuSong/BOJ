#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool check[1001];

void BFS(int node, const vector<vector<int>>& vGraph)
{
	queue<int> qSearch;
	qSearch.push(node);
	check[node] = true;

	while (!qSearch.empty())
	{
		int now = qSearch.front();
		qSearch.pop();
		for (int next : vGraph[now])
		{
			if (!check[next])
			{
				check[next] = true;
				qSearch.push(next);
			}
		}
	}
	return;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> vGraph(N+1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vGraph[a].push_back(b);
		vGraph[b].push_back(a);
	}

	int nResult = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!check[i])
		{
			nResult++;
			BFS(i, vGraph);
		}
	}

	cout << nResult << endl;
	return 0;
}