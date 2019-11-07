#include<iostream>
#include<vector>
#include<algorithm>
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
	int g = GCD(A, B);
	int n1 = A / g;
	int n2 = B / g;
	return g * n1 * n2;
}
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		long long sum = 0;
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
				sum += GCD(v[i], v[j]);
		cout << sum << endl;
	}
	return 0;
}