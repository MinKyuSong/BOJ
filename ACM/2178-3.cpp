#include<cstdio>
#include<tuple>
#include<utility>
#include<queue>
using namespace std;

int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int map[100][100];
int step[100][100];

bool valid(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void BFS()
{
	queue<pair<int, int>> qSearch;
	qSearch.push(make_pair(0, 0));
	step[0][0] = 1;
	while (!qSearch.empty())
	{
		int nx, ny;
		tie(nx, ny) = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 4; i++)
			if(valid(nx+dx[i],ny+dy[i]))
				if (map[nx + dx[i]][ny + dy[i]] == 1 &&
					step[nx + dx[i]][ny + dy[i]] == 0)
				{
					qSearch.push(make_pair(nx + dx[i],ny + dy[i]));
					step[nx + dx[i]][ny + dy[i]] = step[nx][ny]+1;
					if (nx + dx[i] == N - 1 && ny + dy[i] == M - 1)
					{
						printf("%d\n", step[N - 1][M - 1]);
						return;
					}
				}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	BFS();
	return 0;
}