#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int, int> loc;

int map[51][51];
int group[51][51];
int dx[] = { 0,0,-1,1,-1,1,-1,1 };
int dy[] = { 1,-1,0,0,1,-1,-1,1 };
int X, Y;

void bfs(int y, int x, int nCnt)
{
	queue<loc> qSearch;
	qSearch.push(make_pair(y, x));
	group[y][x] = nCnt;
	while (!qSearch.empty())
	{
		loc nTemp = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 8; i++)
			if (nTemp.first + dy[i] >= 0 && nTemp.first + dy[i] < Y
				&& nTemp.second + dx[i] >= 0 && nTemp.second + dx[i] < X)
				if (map[nTemp.first + dy[i]][nTemp.second + dx[i]] == 1
					&& group[nTemp.first + dy[i]][nTemp.second + dx[i]] == 0)
				{
					group[nTemp.first + dy[i]][nTemp.second + dx[i]] = nCnt;
					qSearch.push(make_pair(nTemp.first + dy[i], nTemp.second + dx[i]));
				}

	}
	return;
}

int main(void)
{
	scanf("%d %d", &X, &Y);
	while (X > 0 && Y > 0)
	{
		for (int i = 0; i < Y; i++)
			for (int j = 0; j < X; j++)
			{
				scanf("%d", &map[i][j]);
				group[i][j] = 0;
			}

		int cnt = 0;

		for (int i = 0; i < Y; i++)
			for (int j = 0; j < X; j++)
			{
				if (map[i][j] == 1 && group[i][j] == 0)
					bfs(i, j, ++cnt);
			}

		printf("%d\n", cnt);
		scanf("%d %d", &X, &Y);
	}

	return 0;
}