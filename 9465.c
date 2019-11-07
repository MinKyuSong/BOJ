#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXN 100000

int map[2][MAXN];
int revmap[2][MAXN];

void mapclear() {
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < MAXN; j++) {
			map[i][j] = 0; revmap[i][j] = 0;
		}
	return;
}
void getmap(int n) {
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	return;
}

int calrev(int n) {
	int i;

	revmap[0][0] = map[0][0];
	revmap[1][0] = map[1][0];
	if (n == 0) return revmap[0][0] > revmap[1][0] ? revmap[0][0] : revmap[1][0];

	revmap[0][1] = map[0][1] + revmap[1][0];
	revmap[1][1] = map[1][1] + revmap[0][0];
	if (n == 1) return revmap[0][1] > revmap[1][1] ? revmap[0][1] : revmap[1][1];

	for (i = 2; i < n; i++) {
		revmap[0][i] = map[0][i] + (revmap[1][i - 1] > revmap[1][i - 2] ? revmap[1][i - 1] : revmap[1][i - 2]);
		revmap[1][i] = map[1][i] + (revmap[0][i - 1] > revmap[0][i - 2] ? revmap[0][i - 1] : revmap[0][i - 2]);
	}

	return revmap[0][n - 1] > revmap[1][n - 1] ? revmap[0][n - 1] : revmap[1][n - 1];
}

int main(void) {
	int nTry, nResult;
	int i, n;

	scanf("%d", &nTry);
	for (i = 0; i < nTry; i++) {
		mapclear();
		scanf("%d", &n);
		getmap(n);
		nResult = calrev(n);
		printf("%d\n", nResult);
	}

	return 0;
}