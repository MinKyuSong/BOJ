#include<iostream>
#include<stack>
using namespace std;

int check[1001];
int pnNodes[1001];
int cnt = 0;

void dfs(int i)
{
	stack<int> sSearch;
	check[i] = ++cnt;
	sSearch.push(i);
	while (!sSearch.empty())
	{
		int nTemp = sSearch.top();
		check[nTemp] = cnt;
		sSearch.pop();
		if (check[pnNodes[nTemp]] == 0)
			sSearch.push(pnNodes[nTemp]);
	}
	return;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int nTry;
	cin >> nTry;
	while (nTry--)
	{
		int N;
		cnt = 0;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			check[i] = 0;
			cin >> pnNodes[i];
		}
		for (int i = 1; i <= N; i++)
			if (check[i] == 0)
				dfs(i);
		cout << cnt << '\n';
	}

	return 0;
}