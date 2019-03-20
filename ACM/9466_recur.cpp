#include<iostream>
using namespace std;

int check[100001];
int Nodes[100001];
int Steps[100001];

int dfs(int n, int nOrder, int& step)
{
	if (check[n] != 0)
	{
		if (Steps[n] != step)
			return 0;
		return nOrder - check[n];
	}
	check[n] = nOrder;
	Steps[n] = step;
	return dfs(Nodes[n], nOrder + 1, step);
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	int nTry;
	cin >> nTry;
	while (nTry--)
	{
		int N, nResult=0;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			check[i] = 0; Steps[i] = 0;
			cin >> Nodes[i];
		}
		for (int i = 1; i <= N; i++)
		{
			if (check[i] == 0)
				nResult += dfs(i, 1, i);
		}
		cout << N-nResult << '\n';
	}
	return 0;
}