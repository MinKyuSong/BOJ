#include<iostream>
using namespace std;

long long nArr[31];

int main(void)
{
	int n;
	cin >> n;
	nArr[0] = 1; nArr[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		nArr[i] = nArr[i - 2] * 3;
		if (i >= 4)
		{
			for (int j = i - 4; j >= 0; j -= 2)
				nArr[i] += (nArr[j] * 2);
		}
	}
	cout << nArr[n] << endl;
	return 0;
}