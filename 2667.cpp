#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;

typedef pair<int, int> corr;
int N;
int map[30][30];
int group[30][30];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans[900];
bool isValid(int y, int x, int dy, int dx)
{
	return (y + dy >= 0 && y + dy < N
		&& x + dx >= 0 && x + dx < N
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
		
		for (int i = 0; i < 4; i++)
			if (isValid(cTemp.first, cTemp.second, dy[i], dx[i]))
			{
				qSearch.push(make_pair(cTemp.first + dy[i], cTemp.second + dx[i]));
				group[cTemp.first + dy[i]][cTemp.second + dx[i]] = cnt;
			}
	}
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);

	int cnt = 0;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && group[i][j] == 0)
				bfs(i, j, ++cnt);
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans[group[i][j]]+=1;
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++)
		printf("%d\n", ans[i]);
	return 0;
}