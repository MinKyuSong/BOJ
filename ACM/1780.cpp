#include<iostream>

using namespace std;

int N;
int map[3000][3000];
int cntm1(0);
int cnt0(0);
int cnt1(0);

bool check(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (map[y][x] != map[j][i])
			{
				return false;
			}
		}
	}
	return true;
}

void solve(int x, int y, int n)
{
	if (check(x, y, n))
	{
		if (map[y][x] == -1) cntm1++;
		else if (map[y][x] == 0) cnt0++;
		else cnt1++;
	}
	else
	{
		int m = n / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				solve(x + i * m, y + j * m, m);
	}
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	solve(0, 0, N);

	cout << cntm1 << endl;
	cout << cnt0 << endl;
	cout << cnt1 << endl;
	return 0;
}