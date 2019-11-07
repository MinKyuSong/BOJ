#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int nInput;
	cin >> nInput;

	typedef pair<int, int> loc;

	vector<loc> vLocs(nInput);
	for (int i = 0; i < nInput; i++)
	{
		cin >> vLocs[i].first >> vLocs[i].second;
	}

	sort(vLocs.begin(), vLocs.end());

	for (auto &a : vLocs)
	{
		cout << a.first << " " << a.second << '\n';
	}

	return 0;
}