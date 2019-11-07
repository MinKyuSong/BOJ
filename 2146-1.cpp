#include<iostream>
#include<tuple>
#include<queue>
using namespace std;

int N;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[100][100];
int group[100][100];
int dist[100][100];
int g;
queue<tuple<int, int>> qDist;

bool valid(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}

void BFS(int x, int y)
{
	queue<tuple<int, int>> qSearch;
	qSearch.push(make_tuple(x, y));
	group[x][y] = g;
	while (!qSearch.empty())
	{
		int nx, ny;
		tie(nx, ny) = qSearch.front();
		qSearch.pop();
		for(int i=0;i<4;i++)
			if(valid(nx+dx[i],ny+dy[i]))
				if (map[nx + dx[i]][ny + dy[i]] == 1 &&
					group[nx + dx[i]][ny + dy[i]] == 0)
				{
					qSearch.push(make_tuple(nx + dx[i], ny + dy[i]));
					group[nx + dx[i]][ny + dy[i]] = g;
				}
	}

}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if (map[i][j] == 1 && group[i][j] == 0)
			{
				g++;
				BFS(i, j);
			}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (group[i][j] != 0)
				qDist.push(make_tuple(i, j));
	while (!qDist.empty())
	{
		int x, y;
		tie(x, y) = qDist.front();
		qDist.pop();
		for (int i = 0; i < 4; i++)
		{
			if (valid(x + dx[i], y + dy[i]))
			{
				if (group[x + dx[i]][y + dy[i]] == 0 && dist[x + dx[i]][y + dy[i]] == 0)
				{
					qDist.push(make_tuple(x + dx[i], y + dy[i]));
					dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
					group[x + dx[i]][y + dy[i]] = group[x][y];
				}
			}
		}
	}

	int nResult = N * N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (valid(x, y))
					if (group[i][j] != group[x][y])
						if (nResult > dist[i][j] + dist[x][y])
							nResult = dist[i][j] + dist[x][y];
			}
		}
	cout << nResult << endl;
	return 0;
}