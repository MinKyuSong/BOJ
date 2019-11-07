#include<iostream>

using namespace std;

int a[500000];
int b[500000];

long long solve(int begin, int end)
{
	if (begin == end)
	{
		return 0;
	}
	int mid=(begin + end) / 2;
	long long ans = solve(begin, mid) + solve(mid + 1, end);
	
	int l = begin;
	int r = mid + 1;
	int pos = 0;

	while (l <= mid || r <= end)
	{
		if (l <= mid && (r > end || a[l] <= a[r]))
		{
			b[pos++] = a[l++];
		}
		else
		{
			// 계산되는 수 주의
			ans += (long long)(mid - l + 1);
			b[pos++] = a[r++];
		}
	}
	for (int i = begin; i <= end; i++)
	{
		a[i] = b[i - begin];
	}
	return ans;
}

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> a[i];

	long long ans=solve(0, N-1);

	cout << ans << endl;
	return 0;
}