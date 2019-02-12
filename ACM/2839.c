#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int nTotal;
	int nDiv, nRem, nResult;

	scanf("%d", &nTotal);

	nDiv = nTotal / 5;
	nRem = nTotal % 5;

	if (nDiv == 0) {
		nResult = (nTotal == 3 ? 1 : -1);
	}
	else {
		switch (nRem)
		{
		case 0:
			nResult = nDiv;
			break;

		case 1:
			nResult = nDiv + 1;
			break;

		case 2:
			nResult = nDiv + 2;
			break;

		case 3:
			nResult = nDiv + 1;
			break;

		case 4:
			nResult = nDiv + 2;
			break;

		default:
			break;
		}
	}
	if (nTotal == 7) {
		nResult = -1;
	}

	printf("%d\n", nResult);

	return 0;
}