#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int getmin(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int main(void) {
	int nHouse, i, nResult;
	int **nColorCosts = NULL;
	int **ColorChoiceCosts = NULL;
	//�� ���� �Է�
	scanf("%d", &nHouse);

	//�ʿ��� �޸� ���� �Ҵ�
	nColorCosts = (int**)malloc(sizeof(int*)*nHouse);

	for (i = 0; i < nHouse; i++) {
		nColorCosts[i] = (int*)malloc(sizeof(int) * 3);
	}

	ColorChoiceCosts = (int**)malloc(sizeof(int*)*nHouse);
	for (i = 0; i < nHouse; i++) {
		ColorChoiceCosts[i] = (int*)malloc(sizeof(int) * 3);
	}

	//�� ���� ������ �Է�
	for (i = 0; i < nHouse; i++) {
		scanf("%d %d %d", &nColorCosts[i][0], &nColorCosts[i][1], &nColorCosts[i][2]);
	}

	//ù��° ������ �Է�
	for (i = 0; i < 3; i++) {
		ColorChoiceCosts[0][i] = nColorCosts[0][i];
	}
	//�ι�° ���� ���������� ������
	for (i = 1; i < nHouse; i++) {
		ColorChoiceCosts[i][0] = nColorCosts[i][0] + getmin(ColorChoiceCosts[i - 1][1], ColorChoiceCosts[i - 1][2]);
		ColorChoiceCosts[i][1] = nColorCosts[i][1] + getmin(ColorChoiceCosts[i - 1][0], ColorChoiceCosts[i - 1][2]);
		ColorChoiceCosts[i][2] = nColorCosts[i][2] + getmin(ColorChoiceCosts[i - 1][0], ColorChoiceCosts[i - 1][1]);
	}

	nResult = ColorChoiceCosts[nHouse-1][0];
	if (ColorChoiceCosts[nHouse-1][1] < nResult)
		nResult = ColorChoiceCosts[nHouse-1][1];
	if (ColorChoiceCosts[nHouse-1][2] < nResult)
		nResult = ColorChoiceCosts[nHouse-1][2];

	printf("%d\n", nResult);

	//�۾� ������ �޸� ��ȯ
	for (i = 0; i < nHouse; i++) {
		free(nColorCosts[i]);
	}
	free(nColorCosts);
	for (i = 0; i < nHouse; i++) {
		free(ColorChoiceCosts[i]);
	}
	free(ColorChoiceCosts);

	return 0;
}