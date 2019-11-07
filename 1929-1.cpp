#include<iostream>
#include<string.h>
#define MAXN 1000001

using namespace std;
bool net[MAXN];
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	memset(net, true, MAXN);
	net[1] = false;
	for (int i = 2; i * i < MAXN; i++)
	{
		if (net[i])
		{
			for (int j = i + i; j < MAXN; j += i)
			{
				net[j] = false;
			}
		}
	}

	int N, M;
	cin >> N >> M;
	for (int i = N; i <= M; i++)
	{
		if (net[i])
			cout << i << endl;
	}
	return 0;
}