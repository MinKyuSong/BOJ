#define _CRT_SECURE_NO_WARNINGS
#include<queue>
#include<utility>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef pair<int, int> loc;

int w,h;
int Map[50][50];
int Group[50][50];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

void bfs(int y, int x, int group)
{
	queue<loc> qSearch;
	qSearch.push(make_pair(y, x));
	Group[y][x] = group;
	while (!qSearch.empty())
	{
		loc lTemp = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 8; i++)
		{
			int ny, nx;
			ny = lTemp.first + dy[i];
			nx = lTemp.second + dx[i];
			if (ny >= 0 && ny < h && nx >= 0 && nx < w)
				if (Map[ny][nx] == 1 && Group[ny][nx] == 0)
				{
					qSearch.push(make_pair(ny, nx));
					Group[ny][nx] = group;
				}
		}
	}
	return;
}

int main(void)
{
	scanf("%d %d", &w,&h);
	while (w != 0 && h != 0)
	{
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				scanf("%d", &Map[i][j]);
				Group[i][j] = 0;
			}
		int nCnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				if (Map[i][j] == 1 && Group[i][j] == 0)
					bfs(i, j, ++nCnt);
			}

		printf("%d\n", nCnt);
		scanf("%d %d", &w, &h);
	}
	return 0;
}