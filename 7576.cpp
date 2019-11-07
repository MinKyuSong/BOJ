#include<iostream>
#include<queue>
using namespace std;

int map[1001][1001];
int check[1001][1001];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int M, N;

bool isValid(int y, int x)
{
	return (x > 0 && x <= M && y > 0 && y <= N)
		&& (map[y][x] != -1 && check[y][x]==-1);
}


int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	queue<pair<int, int>> qSearch;
	cin >> M >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
			check[i][j] = -1;
			if (map[i][j] == 1)
			{
				qSearch.push(make_pair(i, j));
				check[i][j] = 0;
			}
		}

	while (!qSearch.empty())
	{
		int y = qSearch.front().first;
		int x = qSearch.front().second;
		qSearch.pop();
		for(int i=0;i<4;i++)
			if (isValid(y + dy[i], x + dx[i]))
			{
				check[y + dy[i]][x + dx[i]] = check[y][x] + 1;
				qSearch.push(make_pair(y + dy[i], x + dx[i]));
			}
	}

	int nResult = 0;
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= M; j++)
		{
			if (nResult < check[i][j])
				nResult = check[i][j];
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j]==0 && check[i][j]==-1)
				nResult = -1; break;
		}

	cout << nResult << '\n';

	return 0;
}