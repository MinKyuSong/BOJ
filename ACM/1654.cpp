#include<iostream>
using namespace std;

long long K, N;
long long nCables[10000];

bool check(int mid)
{
	long long cnt = 0;
	for (int i = 0; i < K; i++)
		cnt += (nCables[i] / mid);
	return cnt >= N;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	cin >> K >> N;

	long long max = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> nCables[i];
		if (nCables[i] > max)
			max = nCables[i];
	}

	long long ans = 0;
	long long l = 1;
	long long r = max;

	while (l <= r)
	{
		long long mid = l + (r - l) / 2;
		if (check(mid))
		{
			if (ans < mid)
				ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}