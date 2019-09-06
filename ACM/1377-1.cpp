#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	
	vector<pair<int,int>> vNums(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vNums[i].first;
		vNums[i].second = i;
	}
	sort(vNums.begin(), vNums.end());
	
	int nResult = 0;
	for (int i = 0; i < N; i++)
	{
		if (nResult < vNums[i].second - i)
			nResult = vNums[i].second - i;
	}
	cout << nResult+1 << endl;
	return 0;
}