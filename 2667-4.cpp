#include<cstdio>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int N;
int g = 0;
int map[26][26];
int check[26][26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<int> vCount;
bool valid(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}
void BFS(int x, int y)
{
	int count = 1;
	queue<pair<int, int>> qSearch;
	qSearch.push(make_pair(x, y));
	check[x][y] = g;
	while (!qSearch.empty())
	{
		int nowx, nowy;
		tie(nowx, nowy) = qSearch.front();
		qSearch.pop();
		for (int i = 0; i < 4; i++)
		{
			if (valid(nowx + dx[i], nowy + dy[i]))
				if (map[nowx + dx[i]][nowy + dy[i]]==1
					&&check[nowx + dx[i]][nowy + dy[i]] == 0)
				{
					count++;
					qSearch.push(make_pair(nowx + dx[i], nowy + dy[i]));
					check[nowx + dx[i]][nowy + dy[i]] = g;
				}
		}
	}
	vCount.push_back(count);
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] != 0 && check[i][j] == 0)
			{
				g++;
				BFS(i, j);
			}
		}
	sort(vCount.begin(), vCount.end());
	printf("%d\n", g);
	for (int i:vCount)
		printf("%d\n", i);
	return 0;
}