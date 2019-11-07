#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<vector<int>> &graph, int nNode, bool* check)
{
	if (check[nNode] == true)
		return;

	cout << nNode << " ";
	check[nNode] = true;

	for (auto &a : graph[nNode])
		dfs(graph, a, check);

	return;
}
void bfs(vector<vector<int>> &graph, int nNode, bool* check)
{
	queue<int> qSearch;
	vector<int> vResult;

	qSearch.push(nNode); check[nNode] = true;
	while (!qSearch.empty())
	{
		int nTemp = qSearch.front();
		vResult.push_back(nTemp);qSearch.pop();

		for (auto &a : graph[nTemp])
		{
			if (check[a] == false)
			{
				qSearch.push(a);
				check[a] = true;
			}
		}
	}
	for (auto &a : vResult)
		cout << a << " ";
	return;
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	int N, M, V;
	cin >> N >> M >> V;

	vector<vector<int>> graph(N+1);
	bool *check = new bool[N + 1];

	for (int i = 0; i < N + 1; i++)
		check[i] = false;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < N + 1; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(graph, V, check);
	cout << "\n";

	for (int i = 0; i < N + 1; i++)
		check[i] = false;

	bfs(graph, V, check);
	cout << "\n";

	delete[] check;
	return 0;
}