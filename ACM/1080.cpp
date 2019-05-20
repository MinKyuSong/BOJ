#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;

int N, M;
int src[51][51];
int dest[51][51];

void swap(int y, int x)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			src[y + i][x + j] = 1 - src[y + i][x + j];
	return;
}

int main(void)
{
	int ans = 0;
	bool flag = true;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &src[i][j]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &dest[i][j]);

	for (int i = 0; i < N-2; i++)
		for (int j = 0; j < M-2; j++)
		{
			if (src[i][j] != dest[i][j])
			{
				ans++;
				swap(i, j);
			}
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (src[i][j] != dest[i][j])
			{
				flag = false;
				break;
			}
	if (flag == false)
		ans = -1;

	printf("%d\n", ans);

	return 0;
}