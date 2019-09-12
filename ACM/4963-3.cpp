#include<iostream>
#include<tuple>
#include<set>
#include<queue>
#include<utility>
using namespace std;
int W, H;
int map[51][51];
int group[51][51];
int dx[] = { 1,-1,1,-1,0,0,1,-1 };
int dy[] = { 1,-1,-1,1,1,-1,0,0 };
bool valid(int x, int y)
{
	return (x >= 0 && x < H && y >= 0 && y < W);
}

void BFS(int x, int y, int g)
{
	queue<pair<int, int>> qSearch;
	qSearch.push(make_pair(x, y));
	group[x][y] = g;
	while (!qSearch.empty())
	{
		int nx, ny;
		tie(nx, ny) = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 8; i++)
			if(valid(nx+dx[i],ny+dy[i]))
				if (map[nx + dx[i]][ny + dy[i]] == 1 && 
					group[nx + dx[i]][ny + dy[i]] == 0)
				{
					qSearch.push(make_pair(nx + dx[i],ny + dy[i]));
					group[nx + dx[i]][ny + dy[i]] = g;
				}
	}

	return;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	while (true)
	{
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
				group[i][j] = 0;
			}

		int nCount = 0;

		for(int i=0;i<H;i++)
			for (int j = 0; j < W; j++)
			{
				if (map[i][j] == 1 && group[i][j] == 0)
				{
					nCount++;
					BFS(i, j, nCount);
				}
			}

		cout << nCount << endl;
	}
	return 0;
}