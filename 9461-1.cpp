#include<iostream>
using namespace std;

long long nArr[101] = { 0,1,1,1,2,2,3,4,5,7,9 };
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 11; i <= N; i++)
			nArr[i] = nArr[i - 2] + nArr[i - 3];
		cout << nArr[N] << endl;
	}
	return 0;
}