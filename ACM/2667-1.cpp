#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> loc;

int map[30][30];
int group[30][30];
int ans[900];
int N;
int vX[] = { -1,0,1,0 };
int vY[] = { 0,-1,0,1 };

void bfs(int y, int x, int nCnt)
{
	queue<loc> qSearch;
	qSearch.push(make_pair(y, x));
	group[y][x] = nCnt;

	while (!qSearch.empty())
	{
		loc locTemp = qSearch.front(); qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = locTemp.first + vY[i];
			int nextX = locTemp.second + vX[i];
			if (nextY < N && nextY >= 0 && nextX < N&&nextX >= 0)
				if (map[nextY][nextX] == 1 && group[nextY][nextX] == 0)
				{
					group[nextY][nextX] = nCnt;
					qSearch.push(make_pair(nextY, nextX));
				}
		}
	}
}

int main(void)
{
	scanf("%d",&N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
			group[i][j] = 0;
		}

	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && group[i][j] == 0)
				bfs(i, j, ++cnt);
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans[group[i][j]]++;

	sort(ans+1, ans+cnt+1);
	printf("%d\n",cnt);
	for (int i = 1; i<=cnt ; i++)
		printf("%d\n",ans[i]);

	return 0;
}