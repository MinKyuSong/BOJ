#include<iostream>
using namespace std;

int main(void)
{
	static bool sieve[1000001];
	int M, N;
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> M >> N;

	sieve[0] = sieve[1] = true;

	for (int i = 2; i*i <= N; i++)
	{
		if (sieve[i] == false)
		{
			for (int j = i+i; j <= N; j+=i)
			{
				sieve[j] = true;
			}
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (sieve[i] == false)
			cout << i << '\n';
	}

	return 0;
}