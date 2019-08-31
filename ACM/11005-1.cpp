#include<iostream>
using namespace std;

void Base_Conversion(int N, int B)
{
	if (N == 0)
		return;
	int t = N % B;
	Base_Conversion(N / B, B);
	if (t > 9)
		cout << char('A' + t - 10);
	else
		cout << t;
	return;
}

int main(void)
{
	int N, B;
	cin >> N >> B;
	Base_Conversion(N, B);
	return 0;
}