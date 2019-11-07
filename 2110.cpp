#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long N, C;

bool check(vector<long long>vllHouse, long long dist)
{
	int cnt = 1;
	int last = vllHouse[0];
	for (auto& i : vllHouse)
	{
		if (i - last >= dist)
		{
			cnt += 1;
			last = i;
		}
	}
	return cnt >= C;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	cin >> N >> C;


	vector<long long> vllHouse(N);
	long long max = 0;
	for (long long i = 0; i < N; i++)
	{
		cin >> vllHouse[i];
		if (max < vllHouse[i])
			max = vllHouse[i];
	}
	sort(vllHouse.begin(), vllHouse.end());

	long long l = 1;
	long long r = max - vllHouse[0];
	long long ans = l;
	while (l <= r)
	{
		long long mid = l + (r - l) / 2;
		if (check(vllHouse, mid))
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