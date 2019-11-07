#include<iostream>
using namespace std;

int nArr[100001];
int n;
int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		nArr[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			if (nArr[i - j * j] + 1 < nArr[i])
				nArr[i] = nArr[i - j * j] + 1;
		}
	}
	cout << nArr[n] << endl;
	return 0;
}