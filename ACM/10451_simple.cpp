#include<iostream>
using namespace std;

int naNodes[1001];
bool check[1001];

void dfs(int i)
{
	if (check[i]) return;
	check[i] = true;
	dfs(naNodes[i]);
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int nTry;
	cin >> nTry;
	while (nTry--)
	{
		int N;
		int ans = 0;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			check[i] = false;
			cin >> naNodes[i];
		}
		for (int i = 1; i <= N; i++)
		{
			if (check[i] == false)
			{
				dfs(i);
				ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}