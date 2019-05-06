#include<iostream>
#include<algorithm>
using namespace std;
int spend[1001];
int wait[1001];
int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> spend[i];

	sort(spend + 0, spend + N);

	int nResult;
	nResult=wait[0] = spend[0];
	for (int i = 1; i < N; i++)
	{
		wait[i] = wait[i - 1] + spend[i];
		nResult += wait[i];
	}
	cout << nResult << endl;
	return 0;
}