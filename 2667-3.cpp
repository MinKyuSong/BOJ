#include<cstdio>
#include<queue>
#include<utility>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int N;
int map[26][26];
int group[26][26];
int g = 0;
int gcount;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
bool valid(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}
void BFS(int x, int y, vector<int>& vCounts)
{
	group[x][y] = g;
	gcount++;
	queue<pair<int, int>> qSearch;
	qSearch.push(make_pair(x, y));
	while (!qSearch.empty())
	{
		int nx, ny;
		tie(nx, ny) = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			if(valid(nx+dx[i],ny+dy[i]))
				if (map[nx + dx[i]][ny + dy[i]] == 1 && group[nx + dx[i]][ny + dy[i]] == 0)
				{
					qSearch.push(make_pair(nx + dx[i], ny + dy[i]));
					gcount++;
					group[nx + dx[i]][ny + dy[i]] = g;
				}
		}
	}
	vCounts.push_back(gcount);
}
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);

	vector<int> vCounts;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			if (group[i][j] == 0 && map[i][j] == 1)
			{
				gcount = 0;
				g++;
				BFS(i, j,vCounts);
			}
		}
	sort(vCounts.begin(), vCounts.end());
	printf("%d\n", g);
	for (int i = 0; i < vCounts.size(); i++)
	{
		printf("%d\n", vCounts[i]);
	}
	return 0;
}