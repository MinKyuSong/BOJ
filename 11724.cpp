#include<iostream>
#include<vector>
using namespace std;

int cnt = 1;
int check[1001] = { 0, };

bool dfs(vector<vector<int>> &graph, int nNode)
{
	if (check[nNode] != 0)
		return false;

	check[nNode] = cnt;

	for (auto &a : graph[nNode])
		dfs(graph, a);
	return true;
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		if(dfs(graph, i))
			cnt++;
	}
	cout << cnt-1 << endl;
	return 0;
}