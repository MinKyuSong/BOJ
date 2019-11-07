#include<iostream>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;

int S;
int map[2000][2000];

void BFS()
{
	queue<tuple<int, int>> qSearch;
	qSearch.push(make_tuple(1, 0));
	map[1][0] = 0;
	while (!qSearch.empty())
	{
		int s, c, n;
		tie(s, c) = qSearch.front();
		qSearch.pop();

		if (map[s][s] < 0)
		{
			map[s][s] = map[s][c] + 1;
			qSearch.push(make_tuple(s, s));
		}
		if(s+c<=S && map[s+c][c]<0)
		{
			map[s+c][c] = map[s][c] + 1;
			qSearch.push(make_tuple(s+c,c));
		}
		if (s - 1 >= 0 && map[s - 1][c] < 0)
		{
			map[s - 1][c] = map[s][c] + 1;
			qSearch.push(make_tuple(s - 1, c));
		}
	}
	int nResult = 2000;
	for (int i = 0; i < 2000; i++)
	{
		if (map[S][i] != -1 && nResult > map[S][i])
			nResult = map[S][i];
	}
	cout << nResult << endl;
	return;
}

int main(void)
{
	memset(map, -1, sizeof(map));
	cin >> S;
	BFS();
	return 0;
}