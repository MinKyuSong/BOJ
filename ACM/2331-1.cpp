#include<iostream>

using namespace std;
static int a[300000];
int mypow(int a, int P)
{
	int nResult = 1;
	for (int i = 0; i < P; i++)
		nResult *= a;
	return nResult;
}
int dfs(int root, int P, int cnt)
{
	if (a[root] != 0)
		return a[root];
	a[root] = cnt;
	int nTemp(root), next = 0;

	while (nTemp != 0)
	{
		next += mypow(nTemp % 10, P);
		nTemp /= 10;
	}

	return dfs(next, P, cnt + 1);
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int A, P;
	cin >> A >> P;
	int cnt = 1, nResult;
	nResult = dfs(A, P, cnt);
	cout << nResult-1 << endl;
	return 0;
}