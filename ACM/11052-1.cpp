#include<iostream>

using namespace std;

int nArrPrice[1001];
int nArrPaid[1001];

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> nArrPrice[i];

	nArrPaid[1] = nArrPrice[1];

	for (int i = 2; i <= N; i++)
	{
		int max = nArrPrice[i];
		for (int j = 1; j < i; j++)
		{
			if (max < nArrPrice[j] + nArrPaid[i - j])
				max = nArrPrice[j] + nArrPaid[i - j];
		}
		nArrPaid[i] = max;
	}
	cout << nArrPaid[N] << endl;
	return 0;
}