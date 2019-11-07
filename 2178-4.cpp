#include<cstdio>
#include<queue>
#include<utility>
#include<tuple>
using namespace std;

int N, M;
int map[100][100];
int check[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool valid(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void BFS(int x, int y)
{
	queue<pair<int, int>> qSearch;
	check[x][y] = 1;
	qSearch.push(make_pair(x, y));

	while (!qSearch.empty())
	{
		int nx, ny;
		tie(nx, ny) = qSearch.front(); qSearch.pop();
		int step = check[nx][ny];
		for (int i = 0; i < 4; i++)
		{
			if (valid(nx + dx[i], ny + dy[i]))
				if (map[nx + dx[i]][ny + dy[i]] == 1
					&& check[nx + dx[i]][ny + dy[i]] == 0)
				{
					check[nx + dx[i]][ny + dy[i]] = step + 1;
					qSearch.push(make_pair(nx + dx[i], ny + dy[i]));
					if (nx + dx[i] == N - 1 && ny + dy[i] == M - 1)
						return;
				}
		}
	}
	return;
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}

	BFS(0, 0);

	printf("%d\n", check[N - 1][M - 1]);
	return 0;
}