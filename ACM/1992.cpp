#include<iostream>

using namespace std;

char map[64][65];

bool same(int y, int x, int n)
{
	for (int i = y; i < y + n; i++)
		for (int j = x; j < x + n; j++)
			if (map[i][j] != map[y][x])
				return false;
	return true;
}
void solve(int y, int x, int n)
{
	if (same(y, x, n))
		cout << map[y][x];
	else
	{
		int m = n / 2;
		cout << "(";

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				solve(y + i * m, x + j * m, m);

		cout << ")";
	}
	return;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			char cInput;
			cin >> cInput;
			map[i][j] = cInput;
		}

	solve(0, 0, N);

	return 0;
}
