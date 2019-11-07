#include<iostream>

using namespace std;

int nCounts[1001] = { 0,1,2, };

int main(void)
{
	int N;
	cin >> N;
	for (int i = 3; i <= N; i++)
	{
		nCounts[i] = (nCounts[i - 1] + nCounts[i - 2]) % 10007;
	}

	cout << nCounts[N] << endl;
	return 0;
}