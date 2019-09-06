#include<iostream>
using namespace std;

static int nArr[10001];

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nArr[temp]++;
	}
	for (int i = 0, j = 0; i < N && j <= 10000;j++)
	{
		if (nArr[j] > 0)
		{
			for (int k = 0; k < nArr[j]; k++,i++)
				cout << j << "\n";
		}
	}
	return 0;
}