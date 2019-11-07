#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> vNums(N);
	for (int i = 0; i < N; i++)
		cin >> vNums[i];
	sort(vNums.begin(), vNums.end());
	for (int i = 0; i < N; i++)
		cout << vNums[i] << "\n";
	return 0;
}