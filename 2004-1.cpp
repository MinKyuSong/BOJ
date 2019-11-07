#include<iostream>
using namespace std;

int main(void)
{
	long long n, m;
	cin >> n >> m;
	
	long long count2 = 0;
	long long count5 = 0;
	for (long long i = 2; i <= n; i *= 2)
		count2 += (n / i);
	for (long long i = 5; i <= n; i *= 5)
		count5 += (n / i);
	for (long long i = 2; i <= m; i *= 2)
		count2 -= (m / i);
	for (long long i = 5; i <= m; i *= 5)
		count5 -= (m / i);
	long long k = n - m;
	for (long long i = 2; i <= k; i *= 2)
		count2 -= (k / i);
	for (long long i = 5; i <= k; i *= 5)
		count5 -= (k / i);

	cout << (count2<count5?count2:count5) << endl;
	return 0;
}