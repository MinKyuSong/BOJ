#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int, int> corr;
int maze[101][101];
int visit[101][101];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int N, M;
bool isValid(int y, int x)
{
	return(y >= 1 && y <= N && x >= 1 && x <= M) && 
		(maze[y][x] == 1 && visit[y][x] == 0);
}
void bfs(int y, int x, int nOrder)
{
	int nVisit = nOrder;

	queue<corr> qSearch;
	qSearch.push(make_pair(y, x));
	visit[y][x] = nVisit;
	while (!qSearch.empty())
	{
		corr pTemp = qSearch.front();
		qSearch.pop();
		if (pTemp.first == N && pTemp.second == M) break;
		for (int i = 0; i < 4; i++)
		{
			corr next = make_pair(pTemp.first + dy[i], pTemp.second + dx[i]);
			if (isValid(next.first,next.second))
			{
				qSearch.push(next);
				visit[next.first][next.second] = visit[pTemp.first][pTemp.second] + 1;
			}
		}
	}
	return;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &maze[i][j]);
			visit[i][j] = 0;
		}
	bfs(1, 1, 1);
	printf("%d\n", visit[N][M]);
	return 0;
}