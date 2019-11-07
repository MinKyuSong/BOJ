#include<iostream>
using namespace std;

static int check[100001];
int pow(int a, int b)
{
	int nResult = 1;
	for (int i = 0; i < b; i++)
		nResult *= a;
	return nResult;
}
int next(int a, int P)
{
	int nTemp(a), nResult(0);
	while (nTemp != 0)
	{
		nResult += pow(nTemp % 10, P);
		nTemp /= 10;
	}
	return nResult;
}
int length(int A, int P, int cnt)
{
	if (check[A] != 0)
	{
		return check[A]-1;
	}
	else
	{
		check[A] = cnt;
		int b = next(A, P);
		return length(b, P, cnt + 1);
	}
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int A, P;
	cin >> A >> P;

	cout << length(A, P, 1) << '\n';
	return 0;
}