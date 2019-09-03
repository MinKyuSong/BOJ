#include<iostream>
#include<string.h>
#define MAXN 1001

using namespace std;
bool net[MAXN];
int main(void)
{
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

	int N;
	cin >> N;
	int nResult = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nResult += net[temp];
	}
	cout << nResult << endl;
	return 0;
}