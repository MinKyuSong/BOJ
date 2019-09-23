#include<iostream>
#include<queue>
#include<utility>
#include<tuple>
using namespace std;

int I;
int map[300][300];
int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };
bool valid(int x, int y)
{
	return (x >= 0 && x < I && y >= 0 && y < I);
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> I;
		for (int i = 0; i < I; i++)
			for (int j = 0; j < I; j++)
				map[i][j] = -1;
		int x, y, tx,ty;
		cin >> tx >> ty;
		queue<pair<int, int>> qSearch;
		map[tx][ty] = 0;
		qSearch.push(make_pair(tx, ty));
		cin >> x >> y;
		if (tx == x && ty == y)
		{
			cout << 0 << endl;
			continue;
		}
		while (!qSearch.empty())
		{
			int nx, ny;
			tie(nx, ny) = qSearch.front(); qSearch.pop();
			for (int i = 0; i < 8; i++)
			{
				if (valid(nx + dx[i], ny + dy[i]))
					if (map[nx + dx[i]][ny + dy[i]] < 0)
					{
						qSearch.push(make_pair(nx + dx[i], ny + dy[i]));
						map[nx + dx[i]][ny + dy[i]] = map[nx][ny] + 1;
						if (nx + dx[i] == x && ny + dy[i] == y)
						{
							cout << map[nx + dx[i]][ny + dy[i]] << endl;
						}
					}
			}
		}
	}
	return 0;
}