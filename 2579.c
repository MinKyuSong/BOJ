#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int stair[301];
int score[301];

void getInput(int* nStairs)
{
	int i,temp;

	scanf("%d", &temp);
	*nStairs=++temp;
	stair[0] = 0;
	for (i = 1; i < temp; i++)
	{
		scanf("%d", &stair[i]);
	}
	return;
}
int getResult(int nStairs)
{
	int i;

	score[1] = stair[1];
	score[2] = stair[1] + stair[2];
	score[3] = stair[1] > stair[2] ? stair[1]+stair[3] : stair[2]+stair[3];

	for (i = 4; i < nStairs; i++)
	{
		score[i] = (score[i - 2] > score[i - 3] + stair[i - 1] ? 
					score[i - 2] : score[i - 3] + stair[i - 1])
					+ stair[i];
	}
	return score[nStairs - 1];
}

int main(void)
{
	int nStairs;
	int nResult;

	getInput(&nStairs);
	nResult = getResult(nStairs);
	printf("%d\n", nResult);

	return 0;
}