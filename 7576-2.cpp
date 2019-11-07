#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int N, M;
int map[1000][1000];
int status[1000][1000];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<tuple<int, int>> qSearch;
bool valid(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < M);
}
void BFS()
{
	while (!qSearch.empty())
	{
		int nx, ny;
		tie(nx, ny) = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			if(valid(nx+dx[i],ny+dy[i]))
				if (map[nx + dx[i]][ny + dy[i]] == 0 && status[nx + dx[i]][ny + dy[i]] == 0)
				{
					qSearch.push(make_tuple(nx + dx[i], ny + dy[i]));
					status[nx + dx[i]][ny + dy[i]] = status[nx][ny] + 1;
				}
		}
	}
	return;
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	
	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1 && status[i][j] == 0)
				qSearch.push(make_tuple(i, j));
		}
	BFS();
	int nResult = 0;
	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0 && status[i][j] == 0)
			{
				nResult = -1;
				cout << nResult << endl;
				return 0;
			}
			else if (status[i][j] > nResult)
				nResult = status[i][j];
		}
	cout << nResult << endl;
	return 0;
}