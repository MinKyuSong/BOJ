#include<iostream>
#include<stack>
using namespace std;
int node[100001];
int group[100001];
int order[100001];

int dfs(int root, int ngroup)
{
	stack<int> sSearch;
	int nOrder = 1;
	sSearch.push(root);
	
	while (!sSearch.empty())
	{
		int nTop = sSearch.top(); sSearch.pop();
		if (group[nTop] == ngroup && group[nTop] != 0) return nOrder - order[nTop];
		if (group[nTop] != ngroup && group[nTop] != 0) return 0;
		group[nTop] = ngroup;
		order[nTop] = nOrder++;
		sSearch.push(node[nTop]);
	}
	return 0;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int nTry;
	cin >> nTry;
	while (nTry--)
	{
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> node[i];
			group[i] = 0;
			order[i] = 0;
		}
		int cnt = 1, nResult = 0;
		for (int i = 1; i <= N; i++)
			if (group[i] == 0)
				nResult += dfs(i, cnt++);
		cout << N - nResult << endl;
	}

	return 0;
}