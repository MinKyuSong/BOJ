#include<iostream>

using namespace std;

int main(void)
{
	int N;
	int A[1001];
	int D[1001];

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	
	A[0] = D[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		int max=0;
		for(int j=0;j<i;j++)
		{
			if (D[j] > max && A[j] < A[i])
				max = D[j];
		}
		D[i] = max + 1;
	}
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (D[i] > max)
			max = D[i];
	}
	cout << max << endl;

	return 0;
}