#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> vNums(N);
	for (int i = 0; i < N; i++)
		cin >> vNums[i];
	nth_element(vNums.begin(), vNums.end() - K, vNums.end(), greater<int>());
	cout << vNums[vNums.size()-K] << endl;
	return 0;
}