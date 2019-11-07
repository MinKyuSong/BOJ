#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void upperhalf(int y, int x);
void sprouse(int y, int x);
void feed(int y, int x);

int dy[] = { 0,0,1,-1,1,-1,1,-1 };
int dx[] = { 1,-1,0,0,1,-1,-1,1 };
vector<int> map[11][11];
int nutri[11][11];
int A[11][11];
int N, M, K;

int main(void)
{
	// ÃÊ±â ÀÔ·Â
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
			nutri[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int y, x, age;
		cin >> y >> x >> age;
		map[y][x].push_back(age);
	}

	while (K--)
	{
		// º½, ¿©¸§
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				upperhalf(i, j);

		// °¡À»
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				sprouse(i, j);
		// °Ü¿ï
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				feed(i, j);
	}

	int nResult = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			nResult += map[i][j].size();
	cout << nResult << endl;
	return 0;
}

void upperhalf(int y, int x)
{
	unsigned int i=0;
	unsigned int death = 0;
	sort(map[y][x].begin(),map[y][x].end());
	
	// ³ªÀÌ¸¸Å­ ¸Ô°í
	for (i = 0; i < map[y][x].size(); i++)
	{
		if (nutri[y][x] >= map[y][x][i])
		{
			nutri[y][x] -= map[y][x][i];
			map[y][x][i]++;
		}
		else
			break;
	}
	// ¸ø¸ÔÀº³ð Á×´Â´Ù
	for (death=i; i < map[y][x].size(); i++)
	{
		nutri[y][x] += (map[y][x][i] / 2);
	}
	while (map[y][x].size() > death)
	{
		map[y][x].pop_back();
	}
}
void sprouse(int y, int x)
{
	for (unsigned int i = 0; i < map[y][x].size(); i++)
	{
		if (map[y][x][i] % 5 == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny >= 1 && ny <= N&&nx >= 1 && nx <= N)
				{
					map[ny][nx].push_back(1);
				}
			}
		}
	}
}
void feed(int y, int x)
{
	nutri[y][x] += A[y][x];
	return;
}