#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;

typedef pair<int, int> corr;
int w, h;
int map[51][51];
int group[51][51];
int dx[] = { 0,0,1,-1,-1,1 ,1,-1};
int dy[] = { 1,-1,0,0,-1 ,-1,1,1};
bool isValid(int y, int x, int dy, int dx)
{
	return (y + dy >= 0 && y + dy < h
		&& x + dx >= 0 && x + dx < w
		&& map[y + dy][x + dx] == 1 && group[y + dy][x + dx] == 0);
}
void bfs(int i, int j, int cnt)
{
	queue<corr> qSearch;
	qSearch.push(make_pair(i, j));
	group[i][j] = cnt;
	while (!qSearch.empty())
	{
		corr cTemp = qSearch.front();
		qSearch.pop();

		for (int i = 0; i < 8; i++)
			if (isValid(cTemp.first, cTemp.second, dy[i], dx[i]))
			{
				qSearch.push(make_pair(cTemp.first + dy[i], cTemp.second + dx[i]));
				group[cTemp.first + dy[i]][cTemp.second + dx[i]] = cnt;
			}
	}
}

int main(void)
{
	scanf("%d %d", &w, &h);
	while (w != 0 && h != 0)
	{
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				scanf("%1d", &map[i][j]);
				group[i][j] = 0;
			}

		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && group[i][j] == 0)
					bfs(i, j, ++cnt);
			}
		}
		printf("%d\n", cnt);
		scanf("%d %d", &w, &h);
	}
	return 0;
}