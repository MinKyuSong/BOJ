#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int N, M, groupCount = 0;
char map[51][51];
int groupCheck[51][51];
int dx[] = { 0,-1,1,0 };
int dy[] = { 1,0,0,-1 };
int bx, by;
bool bResult = false;
bool valid(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < M);
}
void BFS(int x, int y)
{
	queue<tuple<int, int, int>> qSearch;
	qSearch.push(make_tuple(x, y, -1));
	groupCheck[x][y] = groupCount;
	while (!qSearch.empty())
	{
		int nx, ny, from;
		tie(nx, ny, from) = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			if (i != abs(from - 3))
				if (valid(nx + dx[i], ny + dy[i]))
					if (map[nx][ny] == map[nx + dx[i]][ny + dy[i]]) {
						if (groupCheck[nx + dx[i]][ny + dy[i]] == 0)
						{
							groupCheck[nx + dx[i]][ny + dy[i]] = groupCount;
							qSearch.push(make_tuple(nx + dx[i],ny + dy[i], i));
						}
						else if (groupCheck[nx + dx[i]][ny + dy[i]] == groupCount)
						{
							bResult = true;
							break;
						}
					}
		}
	}
	return;
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (groupCheck[i][j] == 0)
			{
				groupCount++;
				BFS(i, j);
				if (bResult)
					goto PRNT;
			}
PRNT:
	if (bResult)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}