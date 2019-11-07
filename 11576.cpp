#include<iostream>
using namespace std;

int main(void)
{
	int A, B, N;
	cin >> A >> B;
	cin >> N;

	long long dec = 0;
	for (int i = 0; i < N; i++, dec *= A)
	{
		long long nTemp;
		cin >> nTemp;
		dec += nTemp;
	}
	dec /= A;

	long long pnTemp[25];
	int nLen = 0;

	while (dec > 0)
	{
		pnTemp[nLen] = dec % static_cast<long long>(B);
		dec /= static_cast<long long>(B);
		nLen++;
	}

	for (int i = nLen - 1; i > 0; i--)
		cout << pnTemp[i] << " ";
	cout << pnTemp[0] << endl;

	return 0;
}