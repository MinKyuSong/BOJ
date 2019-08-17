#include<iostream>

using namespace std;

static int nCounts[1000001];

int getMin3(int a, int b, int c)
{
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}

int main(void)
{
	int N;
	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		int temp1 = 1000001, temp2 = 1000001;
		if (i % 3 == 0)
		{
			temp1 = nCounts[i / 3];
		}
		if (i % 2 == 0)
		{
			temp2 = nCounts[i / 2];
		}

		nCounts[i] = getMin3(temp1, temp2, nCounts[i - 1]) + 1;
	}
	cout << nCounts[N] << endl;
	return 0;
}