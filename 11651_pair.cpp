#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int nInput;
	cin >> nInput;

	typedef pair<int, int> loc;
	vector<loc> vLocs(nInput);

	for (int i = 0; i < nInput; i++)
		cin >> vLocs[i].second >> vLocs[i].first;

	sort(vLocs.begin(), vLocs.end());

	for (int i = 0; i < nInput; i++)
		cout << vLocs[i].second <<' '<< vLocs[i].first << '\n';

	return 0;
}