#include<iostream>
#include<vector>

using namespace std;

vector<int> vGraph[1001];
int check[1001];

void dfs(int root, int nGroup)
{
	check[root] = nGroup;
	for (unsigned int i = 0; i < vGraph[root].size(); i++)
		if (check[vGraph[root][i]] == 0)
			dfs(vGraph[root][i], nGroup);
	return;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int v, u;
		cin >> v >> u;
		vGraph[v].push_back(u);
		vGraph[u].push_back(v);
	}


	for (int i = 1; i <= N; i++)
		check[i] = 0;
	
	int nGroup = 0;
	for (int i = 1; i <= N; i++)
		if (check[i] == 0)
			dfs(i, ++nGroup);
	cout << nGroup << endl;

	return 0;
}