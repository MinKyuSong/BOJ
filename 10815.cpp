#include<iostream>
#include<algorithm>
using namespace std;

int* pnArr;
int binSearch(int l, int r, const int& t)
{
	int m = l + (r - l) / 2;
	if (l > r)
		return 0;
	if (pnArr[m] == t)
		return 1;
	else if (pnArr[m] > t)
		return binSearch(l, m-1, t);
	else
		return binSearch(m + 1, r, t);
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	pnArr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> pnArr[i];
	sort(pnArr, pnArr + N);
	
	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		cout << binSearch(0, N-1, temp) << " ";
	}
	cout << endl;

	delete[] pnArr;
	return 0;
}