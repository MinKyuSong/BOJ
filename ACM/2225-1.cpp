#include<iostream>
#define res 1000000000
using namespace std;

int N, K;
static long long map[201][201];
int main(void)
{
	cin >> N >> K;

	map[0][0] = 1;
	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{

			for (int k = 0; k <= j; k++)
			{
				map[i][j] += map[i - 1][j - k];
				map[i][j] %= res;
			}
		}
	}

	cout << map[K][N] << endl;
	return 0;
}