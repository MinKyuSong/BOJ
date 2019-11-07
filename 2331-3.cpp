#include<iostream>
using namespace std;

int A, P;
int check[300000];

int power(int base, int expo)
{
	int nResult = 1;
	for (int i = 0; i < expo; i++)
		nResult *= base;
	return nResult;
}
int DFS(int start, int count)
{
	check[start] = count++;
	int next = 0;
	while (start > 0)
	{
		next += power(start % 10, P);
		start /= 10;
	}
	if (check[next] > 0)
		return check[next] - 1;
	else
		return DFS(next, count);
}

int main(void)
{
	cin >> A >> P;
	int nResult;
	nResult=DFS(A, 1);
	cout << nResult << endl;
	return 0;
}