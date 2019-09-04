#include<iostream>

using namespace std;

int main(void)
{
	long long nResult = 1;
	int N;
	cin >> N;
	for (long long i = 1; i <= N; i++)
		nResult *= i;
	cout << nResult << endl;
	return 0;
}