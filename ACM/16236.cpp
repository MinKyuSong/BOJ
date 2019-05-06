#include<iostream>
#include<utility>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;

typedef pair<int, int> loc;
typedef pair<int, loc> secloc;

vector<loc> fish;
int N;
int baby = 2;
int feed = 0;
int nResult = 0;
int before = 0;
bool flag = false;
int map[21][21];
int cnt[21][21];
int dx[] = { 0,-1,1,0 };
int dy[] = { -1,0,0,1 };

void clean(void)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cnt[i][j] = -1;
	return;
}
void bfs(int y, int x)
{
	queue<loc> qSearch;
	qSearch.push(make_pair(y, x));
	clean();
	fish.clear();
	cnt[y][x] = 0;
	before = 0;
	flag = false;

	while (!qSearch.empty())
	{
		loc lTemp = qSearch.front();
		qSearch.pop();
		// 같은 시간동안 갈 수 있는 구간들 중에 물고기가 있다면
		if (cnt[lTemp.first][lTemp.second] != before &&
			!fish.empty())
		{
			flag = true;
			sort(fish.begin(), fish.end());
			loc lTemp = fish.front();
			nResult += cnt[lTemp.first][lTemp.second];
			map[lTemp.first][lTemp.second] = 0;
			feed++;
			if (feed >= baby)
			{
				feed = 0;
				baby++;
			}
			return;
		}
		else if (cnt[lTemp.first][lTemp.second] != before)
			before = cnt[lTemp.first][lTemp.second];
		for (int i = 0; i < 4; i++)
		{
			int ny = lTemp.first + dy[i];
			int nx = lTemp.second + dx[i];
			if (ny >= 0 && ny < N&&nx >= 0 && nx < N)
			{
				// 갈 수 있는 곳
				if (map[ny][nx] <= baby && cnt[ny][nx] < 0)
				{
					cnt[ny][nx] = cnt[lTemp.first][lTemp.second] + 1;
					qSearch.push(make_pair(ny, nx));
				}
				// 먹을 수 있는 거 별도 저장
				if (map[ny][nx] < baby && map[ny][nx]>0)
				{
					fish.push_back(make_pair(ny, nx));
				}
			}
		}
	}
	return;
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				bfs(i, j);
			}
	while (flag)
	{
		loc lTemp = fish.front();
		bfs(lTemp.first, lTemp.second);
	}
	cout << nResult << endl;
	return 0;
}