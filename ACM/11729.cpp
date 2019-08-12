#include<cstdio>

void solve(int n, int src, int dst)
{
	if (n == 0)
		return;
	solve(n - 1, src, 6 - src - dst);
	printf("%d %d\n", src, dst);
	solve(n - 1, 6 - src - dst, dst);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	printf("%d\n", (1 << N) - 1);
	solve(N, 1, 3);

	return 0;
}