#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long N, M;

bool check(vector<long long>& vllTrees, long long cut)
{
	long long cnt = 0;
	for (auto& i : vllTrees)
	{
		if (i > cut)
			cnt += (i - cut);
	}
	return cnt >= M;
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	cin >> N >> M;

	vector<long long> vllTrees(N);
	long long max = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> vllTrees[i];
		if (max < vllTrees[i])
			max = vllTrees[i];
	}

	long long l = 0;
	long long r = max;
	long long ans = 0;
	while (l <= r)
	{
		long long mid = l + (r - l) / 2;
		if (check(vllTrees, mid))
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