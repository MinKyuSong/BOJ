#include<iostream>
#include<queue>
#include<utility>
#include<tuple>
using namespace std;

int W, H;

int map[50][50];
int check[50][50];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
bool valid(int x, int y)
{
	return (x >= 0 && x < H && y >= 0 && y < W);
}
void BFS(int x, int y, int g)
{
	queue<pair<int, int>> qSearch;
	check[x][y] = g;
	qSearch.push(make_pair(x, y));

	while (!qSearch.empty())
	{
		int nx, ny;
		tie(nx, ny) = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 8; i++)
		{
			if (valid(nx + dx[i], ny + dy[i]))
				if (map[nx + dx[i]][ny + dy[i]] == 1
					&& check[nx + dx[i]][ny + dy[i]] == 0)
				{
					check[nx + dx[i]][ny + dy[i]] = g;
					qSearch.push(make_pair(nx + dx[i], ny + dy[i]));
				}
		}
	}
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	cin >> W >> H;
	while (W != 0 && H != 0)
	{
		for(int i=0;i<H;i++)
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
				check[i][j] = 0;
			}
		int count = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (map[i][j] == 1 && check[i][j] == 0)
				{
					count++;
					BFS(i, j, count);
				}
			}
		cout << count << endl;
		cin >> W >> H;
	}
	return 0;
}