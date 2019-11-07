#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int N, M, K;
	cin >> N >> M >> K;

	int nResult = 0;
	while (N >= 2 && M >= 1 && N + M-3 >= K)
	{
		nResult++;
		N -= 2;
		M -= 1;
	}
	cout << nResult << endl;
	
	return 0;
}