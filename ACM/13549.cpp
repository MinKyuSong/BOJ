#include<iostream>
#include<deque>
using namespace std;
constexpr int MAXN = 1000000;
bool check[MAXN];
int sec[MAXN];

int main(void)
{
	int N, K;
	cin >> N >> K;
	
	deque<int> d;

	check[N] = true;
	sec[N] = 0;
	d.push_back(N);
	while (!d.empty())
	{
		int now = d.front();
		d.pop_front();
		if(now*2<MAXN)
			if (!check[now * 2])
			{
				check[now * 2] = true;
				sec[now * 2] = sec[now];
				d.push_front(now * 2);
			}
		if(now+1<MAXN)
			if (!check[now + 1])
			{
				check[now + 1] = true;
				sec[now + 1] = sec[now] + 1;
				d.push_back(now + 1);
			}
		if(now-1>=0)
			if (!check[now - 1])
			{
				check[now - 1] = true;
				sec[now - 1] = sec[now] + 1;
				d.push_back(now - 1);
			}
	}

	cout << sec[K] << endl;
	return 0;
}