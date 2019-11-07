#include<iostream>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int nCount = 0;
	for (int i = 5; i <= N; i++)
	{
		int t(i);
		while (t % 5 == 0)
		{
			t /= 5;
			nCount++;
		}
	}
	cout << nCount << endl;
	return 0;
}