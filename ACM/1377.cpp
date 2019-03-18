#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	vector<pair<int, int>> vSortee(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vSortee[i].first;
		vSortee[i].second = i;
	}
	sort(vSortee.begin(), vSortee.end());
	
	int nResult = 0;
	for (int i = 0; i < N; i++)
	{
		if (nResult < vSortee[i].second - i)
			nResult = vSortee[i].second - i;
	}

	cout << nResult+1 << '\n';
	return 0;
}