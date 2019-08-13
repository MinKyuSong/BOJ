#include<iostream>

using namespace std;

char map[6562][6562];

void solve(int y, int x, int n)
{
	if (n == 1)
	{
		map[y][x] = '*';
		return;
	}
	int m = n / 3;
	for(int i=0;i<3;i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
			{
				for (int p = 0; p < m; p++)
					for (int q = 0; q < m; q++)
						map[y + i * m + p][x + j * m + q] = ' ';
			}
			else
			{
				solve(y + i * m, x + j * m, m);
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
	for (int i = 0; i < N; i++)
		map[i][N] = 0;

	solve(0, 0, N);

	for (int i = 0; i < N; i++)
		cout << map[i] << endl;

	return 0;
}