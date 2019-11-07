#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vGraph[1001];
bool check[1001];

void dfs(int root)
{
	if (check[root]) return;
	cout << root << ' ';
	check[root] = true;
	for (unsigned int i = 0; i < vGraph[root].size(); i++)
		dfs(vGraph[root][i]);
	return;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N, M, V;
	cin >> N >> M >> V;
	for (int i = 0; i <= N; i++)
		check[i] = false;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vGraph[a].push_back(b);
		vGraph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		sort(vGraph[i].begin(), vGraph[i].end());
	
	dfs(V);
	cout << '\n';

	for (int i = 0; i <= N; i++)
		check[i] = false;
	queue<int> qSearch;
	qSearch.push(V);
	check[V] = true;
	while (!qSearch.empty())
	{
		int nTop = qSearch.front(); qSearch.pop();
		cout << nTop << ' ';
		for (unsigned int i = 0; i < vGraph[nTop].size(); i++)
		{
			if (!check[vGraph[nTop][i]])
			{
				check[vGraph[nTop][i]] = true;
				qSearch.push(vGraph[nTop][i]);
			}
		}
	}
	cout << '\n';
	return 0;
}
