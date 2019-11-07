#include<iostream>
#include<utility>
#include<queue>
#include<tuple>
using namespace std;

int N, M;
int map[1000][1000];
int check[1000][1000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool valid(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < M);
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> M >> N;
	queue<pair<int, int>> qSearch;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int t;
			cin >> t;
			map[i][j]=t;
			if (t == 1)
				qSearch.push(make_pair(i, j));
		}
	
	while (!qSearch.empty())
	{
		int nx, ny;
		tie(nx, ny) = qSearch.front(); qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			if(valid(nx+dx[i],ny+dy[i]))
				if (map[nx + dx[i]][ny + dy[i]] == 0
					&& check[nx + dx[i]][ny + dy[i]]==0)
				{
					qSearch.push(make_pair(nx + dx[i], ny + dy[i]));
					check[nx + dx[i]][ny + dy[i]] = check[nx][ny] + 1;
				}
		}
	}
	int nResult = -1;
	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++)
		{
			if (check[i][j] > nResult)
				nResult = check[i][j];
			if (map[i][j] == 0 && check[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	cout << nResult << endl;
	return 0;
}