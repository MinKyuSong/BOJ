#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 100001
int visit[MAXN];
int N, K;

int main(void)
{
	cin >> N >> K;
	memset(visit, -1, sizeof(visit));

	queue<int>q;
	q.push(N);
	visit[N] = 0;
	if (N == K)
	{
		cout << visit[N] << endl;
		return 0;
	}
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		if (n - 1 >= 0)
			if (visit[n - 1] < 0)
			{
				q.push(n - 1);
				visit[n - 1] = visit[n] + 1;
				if (n - 1 == K)
				{
					cout << visit[n - 1] << endl;
					return 0;
				}
			}
		if (n + 1 < MAXN)
			if (visit[n + 1] < 0)
			{
				q.push(n + 1);
				visit[n + 1] = visit[n] + 1;
				if (n + 1 == K)
				{
					cout << visit[n + 1] << endl;
					return 0;
				}
			}
		if (n * 2 < MAXN)
			if (visit[n * 2] < 0)
			{
				q.push(n * 2);
				visit[n * 2] = visit[n] + 1;
				if (n * 2 == K)
				{
					cout << visit[n * 2] << endl;
					return 0;
				}
			}

	}
	return 0;
}