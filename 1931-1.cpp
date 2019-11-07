#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int main(void)
{
	int N;
	vector<pair<int, int>> timelist;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		timelist.push_back(make_pair(b, a));
	}

	sort(timelist.begin(), timelist.end());

	int nResult = 1;
	int now = 0;
	for (int i = 1; (now < N) && (i < N); i++)
	{
		if (timelist[now].first <= timelist[i].second)
		{
			now = i;
			nResult++;
		}
	}

	cout << nResult << endl;

	return 0;
}