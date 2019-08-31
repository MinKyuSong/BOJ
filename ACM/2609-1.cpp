#include<iostream>

using namespace std;
void myswap(int& a, int& b)
{
	int t(a);
	a = b;
	b = t;
	return;
}
int GCD(int A, int B)
{
	while (B > 0)
	{
		int t = A % B;
		A = B;
		B = t;
	}
	return A;
}
int LCM(int A, int B)
{
	int g= GCD(A, B);
	int n1 = A / g;
	int n2 = B / g;
	return g * n1 * n2;
}
int main(void)
{
	int A, B;
	cin >> A >> B;
	if (A < B)
		myswap(A, B);
	cout << GCD(A, B) << endl;
	cout << LCM(A, B) << endl;
	return 0;
}