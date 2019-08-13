#include<iostream>

using namespace std;

char map[4000][8000];

void solve(int y,int x, int n)
{
	if (n == 3)
	{
		map[y][x] = '*';
		map[y + 1][x - 1] = '*'; map[y + 1][x] = ' '; map[y + 1][x + 1] = '*';
		for (int i = 0; i < 5; i++)
			map[y + 2][x - 2 + i]='*';
		return;
	}
	
	int m = n / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			if (i == 1 && j == 1)
			{
				for (int p = 0; p < m; p++)
					for (int q = 0; q < m; q++)
						map[y + i * m + p][x + j * m + q] = ' ';
			}
			else
			{
				solve(y + i * m, x + i * m, m);
				for (int p = 0; p < m; p++)
					for (int q = 0; q < m; q++)
						map[y + i * m + p][x + j * m + q] = map[y + p][x + q];
			}
		}
	return;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	for (int i = 0; i < 4000; i++)
		for (int j = 0; j < 8000; j++)
			map[i][j] = ' ';

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
			map[i][j] = ' ';
		map[i][i + N] = 0;
	}

	solve(0,N-1, N);

	for (int i = 0; i < N; i++)
		cout << map[i] << endl;
	
	return 0;
}