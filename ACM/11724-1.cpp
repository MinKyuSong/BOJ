#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;
vector<int> vGraph[1001];
int check[1001];
int cnt = 0;
void dfs(int root)
{
	check[root] = cnt;
	for (unsigned int i = 0; i < vGraph[root].size(); i++)
	{
		if (check[vGraph[root][i]] == 0)
			dfs(vGraph[root][i]);
	}
	return;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		check[i] = 0;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vGraph[a].push_back(b);
		vGraph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		if (check[i] == 0)
		{
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << endl;
	return 0;
}
