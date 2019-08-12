#include<iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int *pnArrA = new int[N];
	int* pnArrB = new int[M];

	for (int i = 0; i < N; i++)
		cin >> pnArrA[i];
	for (int i = 0; i < M; i++)
		cin >> pnArrB[i];

	int l = 0, r = 0;

	while (l < N && r < M)
	{
		if (pnArrA[l] < pnArrB[r])
			cout << pnArrA[l++] << " ";
		else
			cout << pnArrB[r++] << " ";
	}
	while (l < N)
		cout << pnArrA[l++] << " ";
	while(r<M)
		cout << pnArrB[r++] << " ";
	cout << endl;

	delete[] pnArrA;
	delete[] pnArrB;
	return 0;
}