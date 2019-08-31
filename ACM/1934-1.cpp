#include<iostream>

using namespace std;
void myswap(long long& a, long long& b)
{
	long long t(a);
	a = b;
	b = t;
	return;
}
long long GCD(long long A, long long B)
{
	while (B > 0)
	{
		long long t = A % B;
		A = B;
		B = t;
	}
	return A;
}
long long LCM(long long A, long long B)
{
	long long g = GCD(A, B);
	long long n1 = A / g;
	long long n2 = B / g;
	return g * n1 * n2;
}
int main(void)
{
	long long T;
	cin >> T;
	while (T--)
	{
		long long A, B;
		cin >> A >> B;
		if (A < B)
			myswap(A, B);
		cout << LCM(A, B) << endl;
	}
	return 0;
}