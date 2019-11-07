#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<utility>

using namespace std;

typedef pair<int, int> loc;

int N;
int map[101][101];
int group[101][101];
int dist[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<loc> qSearch;

void bfs(int y, int x, int cnt)
{
	qSearch.push(make_pair(y, x));
	group[y][x] = cnt;
	while (!qSearch.empty())
	{
		loc lTemp = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = lTemp.first + dy[i];
			int nx = lTemp.second + dx[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<N)
				if (map[ny][nx] == 1 && group[ny][nx] == 0)
				{
					group[ny][nx] = cnt;
					qSearch.push(make_pair(ny, nx));
				}
		}
	}
}
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			group[i][j] = 0;
			dist[i][j] = 0;
		}
	
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (group[i][j] == 0 && map[i][j] == 1)
				bfs(i, j, ++cnt);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (group[i][j] != 0)
				qSearch.push(make_pair(i, j));

	while (!qSearch.empty())
	{
		loc lTemp = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = lTemp.first + dy[i];
			int nx = lTemp.second + dx[i];
			if (nx >= 0 && nx < N&&ny >= 0 && ny < N)
				if (group[ny][nx]==0 && dist[ny][nx] == 0)
				{
					group[ny][nx] = group[lTemp.first][lTemp.second];
					dist[ny][nx] = dist[lTemp.first][lTemp.second] + 1;
					qSearch.push(make_pair(ny, nx));
				}
		}
	}
	int nResult = 200;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N)
					if (group[ny][nx] != group[i][j])
						if (nResult > dist[ny][nx] + dist[i][j])
							nResult = dist[ny][nx] + dist[i][j];
			}
		}
	printf("%d\n", nResult);

	return 0;
}