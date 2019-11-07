#include<cstdio>
#include<cstring>
#include<deque>
#include<tuple>
using namespace std;

int map[100][100];
int check[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N,M;

bool valid(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void BFS()
{
	deque<tuple<int, int>> d;

	d.push_back(make_tuple(0, 0));
	check[0][0] = 0;

	while (!d.empty())
	{
		int x, y;
		tie(x, y) = d.front();
		d.pop_front();

		for (int i = 0; i < 4; i++)
		{
			if(valid(x+dx[i],y+dy[i]))
				if (check[x + dx[i]][y + dy[i]] < 0)
				{
					if (map[x + dx[i]][y + dy[i]] == 0)
					{
						d.push_front(make_tuple(x + dx[i], y + dy[i]));
						check[x + dx[i]][y + dy[i]] = check[x][y];
					}
					else
					{
						d.push_back(make_tuple(x + dx[i], y + dy[i]));
						check[x + dx[i]][y + dy[i]] = check[x][y] + 1;
					}
				}
		}
	}
	return;
}

int main(void)
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	memset(check, -1, sizeof(check));
	BFS();
	printf("%d", check[N - 1][M - 1]);
	return 0;
}