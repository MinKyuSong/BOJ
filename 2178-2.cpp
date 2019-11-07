#define _CRT_SECURE_NO_WARNINGS
#include<queue>
#include<utility>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef pair<int, int> loc;

int w, h;
int Map[1001][1001];
int Group[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main(void)
{
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			scanf("%d", &Map[i][j]);
			Group[i][j] = 0;
		}

	queue<loc> qSearch;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (Map[i][j] == 1)
			{
				qSearch.push(make_pair(i, j));
			}

	while (!qSearch.empty())
	{
		loc lTemp = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny, nx;
			ny = lTemp.first + dy[i];
			nx = lTemp.second + dx[i];
			if (ny >= 0 && ny < h && nx >= 0 && nx < w)
				if (Map[ny][nx] == 0 && Group[ny][nx] == 0)
				{
					qSearch.push(make_pair(ny, nx));
					Group[ny][nx] = Group[lTemp.first][lTemp.second] + 1;
				}
		}
	}
	int nResult = -1;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			if (Group[i][j] > nResult)
				nResult = Group[i][j];
			if (Map[i][j] == 0 && Group[i][j] == 0)
			{
				nResult = -1;
				printf("%d\n", nResult);
				return 0;
			}
		}

	printf("%d\n", nResult);

	return 0;
}