#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;

int N;
int map[101][101];
int group[101][101];
int dist[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int g = 0;
queue<tuple<int, int, int>> qDist;

bool valid(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}
void GBFS(int x, int y)
{
	queue<tuple<int, int>> qSearch;
	qSearch.push(make_tuple(x, y));
	qDist.push(make_tuple(x, y, g));
	group[x][y] = g;
	while (!qSearch.empty())
	{
		int nx, ny;
		tie(nx, ny) = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			if(valid(nx+dx[i],ny+dy[i]))
				if (map[nx + dx[i]][ny + dy[i]] == 1
					&& group[nx + dx[i]][ny + dy[i]] == 0)
				{
					group[nx + dx[i]][ny + dy[i]] = g;
					qSearch.push(make_tuple(nx + dx[i], ny + dy[i]));
					qDist.push(make_tuple(nx + dx[i], ny + dy[i],g));
				}
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
			if (map[i][j] != 0 && group[i][j] == 0)
			{
				g++;
				GBFS(i, j);
			}
	int dMin = 10000;
	while (!qDist.empty())
	{
		int x, y, gt;
		tie(x, y, gt) = qDist.front();
		qDist.pop();
		for (int i = 0; i < 4; i++)
		{
			if (valid(x + dx[i], y + dy[i]))
				if (map[x + dx[i]][y + dy[i]] == 0
					&& group[x + dx[i]][y + dy[i]] != group[x][y])
				{
					if (dist[x + dx[i]][y + dy[i]] != 0)
					{
						if (dMin > dist[x + dx[i]][y + dy[i]] + dist[x][y])
							dMin = dist[x + dx[i]][y + dy[i]] + dist[x][y];
					}
					else
					{
						group[x + dx[i]][y + dy[i]] = gt;
						dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
						qDist.push(make_tuple(x + dx[i], y + dy[i], gt));
					}
				}
		}
	}
	cout << dMin << endl;
	return 0;
}