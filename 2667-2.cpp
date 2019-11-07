#define _CRT_SECURE_NO_WARNINGS
#include<queue>
#include<utility>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef pair<int, int> loc;

int N;
int Map[30][30];
int Group[30][30];
int Count[900];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int y, int x, int group)
{
	queue<loc> qSearch;
	qSearch.push(make_pair(y, x));
	Group[y][x] = group;
	while (!qSearch.empty())
	{
		loc lTemp = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny, nx;
			ny = lTemp.first + dy[i];
			nx = lTemp.second + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N)
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
	scanf("%1d", &N);
	for (int i = 0; i <= 900; i++)
		Count[i] = 0;
	for (int i = 0; i < N; i++)
		for (int j =0; j < N; j++)
		{
			scanf("%1d", &Map[i][j]);
			Group[i][j] = 0;
		}
	int nCnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == 1 && Group[i][j] == 0)
				bfs(i, j, ++nCnt);
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Count[Group[i][j]]++;
	sort(Count+1, Count+nCnt+1);

	printf("%d\n", nCnt);
	for (int i = 1; i <= nCnt; i++)
		printf("%d\n", Count[i]);
	return 0;
}