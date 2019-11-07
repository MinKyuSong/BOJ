#include<iostream>
using namespace std;

int N, M;
int nArrTime[10001];

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> nArrTime[i];
	if (N <= M)
	{
		cout << N << endl;
		return 0;
	}

	long long l = 0;
	long long r = 2000000000LL * 1000000LL;

	while (l <= r)
	{
		long long mid = l + (r - l) / 2;
		long long begin = 0;
		long long end = M;
		for (int i = 0; i < M; i++)
			end += mid / nArrTime[i];

		begin = end;
		
		for (int i = 0; i < M; i++)
			if (mid % nArrTime[i] == 0)
				begin--;

		begin++;

		if (N < begin)
			r = mid - 1;
		else if (N > end)
			l = mid + 1;
		else
		{
			// 몇 번째 놀이기구를 타는지 구하는 과정
			for (int i = 0; i < M; i++)
			{
				if (mid % nArrTime[i] == 0)
				{
					if (N == begin)
					{
						cout << i+1 << endl;
						return 0;
					}
					begin++;
				}
			}
		}
	}
	return 0;
}