#include<iostream>
using namespace std;

long long end0[91];
long long end1[91];

int main(void)
{
	int N;
	cin >> N;

	end0[1] = 0;
	end1[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		end0[i] = end0[i - 1] + end1[i - 1];
		end1[i] = end0[i - 1];
	}
	cout << end0[N] + end1[N] << endl;
	return 0;
}