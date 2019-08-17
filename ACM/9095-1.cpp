#include<iostream>

using namespace std;
static int nCounts[11] = {0,1,2,4};
int main(void)
{
	int T;
	cin >> T;

	for (int i = 4; i < 11; i++)
	{
		nCounts[i] = nCounts[i - 3] + nCounts[i - 2] + nCounts[i - 1];
	}
	while (T--)
	{
		int N;
		cin >> N;
		cout << nCounts[N] << endl;
	}
	return 0;
}