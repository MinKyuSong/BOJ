#include<iostream>
#include<vector>
using namespace std;

bool check[1001];

void DFS(int start, const vector<vector<int>>& vVertex)
{
	check[start] = true;
	for (int i = 0; i < vVertex[start].size(); i++)
	{
		if (!check[vVertex[start][i]])
			DFS(vVertex[start][i], vVertex);
	}
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> vVertex(N+1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vVertex[a].push_back(b);
		vVertex[b].push_back(a);
	}

	int nResult = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!check[i])
		{
			nResult++;
			DFS(i, vVertex);
		}
	}
	cout << nResult << endl;

	return 0;
}