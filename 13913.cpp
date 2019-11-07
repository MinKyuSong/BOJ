#include<iostream>#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
constexpr int MAXN(100001);
int visit[MAXN];
int from[MAXN];
int N, K;

void print(int node)
{
	if (node != N)
		print(from[node]);
	cout << node << " ";
}
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
		cout << N << endl;
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
				from[n - 1] = n;
				if (n - 1 == K)
					break;
			}
		if (n + 1 < MAXN)
			if (visit[n + 1] < 0)
			{
				q.push(n + 1);
				visit[n + 1] = visit[n] + 1;
				from[n + 1] = n;
				if (n + 1 == K)
					break;
			}
		if (n * 2 < MAXN)
			if (visit[n * 2] < 0)
			{
				q.push(n * 2);
				visit[n * 2] = visit[n] + 1;
				from[n * 2] = n;
				if (n * 2 == K)
					break;
			}

	}
	cout << visit[K] << endl;
	print(K);
	cout << endl;
	return 0;
}