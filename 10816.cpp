#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> nInputs(N);
	for (int i = 0; i < N; i++)
		cin >> nInputs[i];
	sort(nInputs.begin(), nInputs.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		auto res = equal_range(nInputs.begin(), nInputs.end(), temp);
		cout << res.second - res.first << " ";
	}
	cout << endl;

	return 0;
}