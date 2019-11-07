#include<iostream>
using namespace std;

int main(void)
{
	long long N, M;
	cin >> N >> M;

	if (N <= 1)
	{
		cout << 1 << endl;
	}
	else if (N == 2)
	{
		int nTemp;
		nTemp = (4 < ((M + 1) / 2) ? 4 : ((M + 1) / 2));
		cout << nTemp << endl;
	}
	else
	{
		if (M < 4)
			cout << M << endl;
		else if (M < 7)
			cout << 4 << endl;
		else
			cout << M - 2 << endl;
	}
	return 0;
}