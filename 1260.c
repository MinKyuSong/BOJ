#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void dfs(int** map, int* check, int start, int numNode);
void bfs(int** map, int* check, int start, int numNode, int* temp);
void clearcheck(int* check, int numNode);

int head = -1;
int tail = 0;

int main(void) {
	int numNode, numArrow, start;
	int i,j;
	int from, to;
	int **map;
	int *check,*temp;

	scanf("%d %d %d", &numNode, &numArrow, &start);

	map = (int**)malloc(sizeof(int*)*(numNode+1));
	check = (int*)malloc(sizeof(int)*(numNode+1));
	temp = (int*)malloc(sizeof(int)*(numNode + 1));

	for (i = 0; i <= numNode; i++) {
		map[i] = (int*)malloc(sizeof(int)*(numNode+1));
		check[i] = 0;
		for (j = 0; j <= numNode; j++)
			map[i][j] = 0;
	}

	for (i = 0; i < numArrow; i++) {
		scanf("%d %d", &from, &to);
		map[from][to] = 1;
		map[to][from] = 1;
	}

	dfs(map, check, start, numNode);
	clearcheck(check, numNode); putchar('\n');
	temp[++head] = start; tail++;
	for (; head <= tail;) {
		bfs(map, check, temp[head], numNode, temp);
	}

	for (i = 0; i <= numNode; i++)
		free(map[i]);
	free(map);
	free(check);
	free(temp);

	return 0;
}

void dfs(int ** map, int * check, int start, int numNode)
{
	int i;
	printf("%d ", start);
	check[start] = 1;
	for (i = 0; i <= numNode; i++) {
		if (map[start][i] == 1 && i != start && check[i] == 0)
			dfs(map, check, i, numNode);
	}
	return;
}

void bfs(int ** map, int * check, int start, int numNode, int* temp)
{
	int i;
	if (check[start] != 1) {
		printf("%d ", start);
		check[start] = 1;
		head++;
	}
	else {
		head++;
		return;
	}
	for (i = 0; i <= numNode; i++) {
		if (map[start][i] == 1 && i != start && check[i] == 0) {
			temp[tail++] = i;
		}
	}
	return;
}

void clearcheck(int * check, int numNode)
{
	int i;
	for (i = 0; i <= numNode; i++) {
		check[i] = 0;
	}
	return;
}