#include<iostream>
using namespace std;

int main(void)
{
	int N, M, K;
	cin >> M >> N >> K;

	int Total = N + M;
	int nResult = 0;
	while (M >= 2 && N >= 1 && (Total-3) >= K)
	{
			M -= 2;
			N -= 1;
			Total -= 3;
			nResult++;
	}

	cout << nResult << endl;
	return 0;
}