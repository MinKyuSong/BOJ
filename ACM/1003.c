#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int zero_arr[41];
	int one_arr[41];
	int nInput,i,j;
	int *testcases = NULL;

	//전체 테스트 케이스 갯수 및 값입력
	scanf("%d", &nInput);
	testcases = (int*)malloc(sizeof(int)*nInput);

	for (i = 0; i < nInput; i++) {
		scanf("%d", &testcases[i]);
	}
	
	//초기화
	for (i = 0; i <= 40; i++) {
		zero_arr[i] = -1;
		one_arr[i] = -1;
	}
	zero_arr[0] = 1; zero_arr[1] = 0;
	one_arr[0] = 0; one_arr[1] = 1;

	//값 구하기
	for (i = 0; i < nInput; i++) {
		if (zero_arr[testcases[i]] == -1 || one_arr[testcases[i]] == -1) {
			for (j = 0; j <= testcases[i]; j++) {
				if (zero_arr[j] == -1 || one_arr[j] == -1) {
					zero_arr[j] = zero_arr[j - 1] + zero_arr[j - 2];
					one_arr[j] = one_arr[j - 1] + one_arr[j - 2];
				}
				else {
					continue;
				}
			}
		}
		else {
			continue;
		}
	}

	//출력
	for (i = 0; i < nInput; i++) {
		printf("%d %d\n", zero_arr[testcases[i]], one_arr[testcases[i]]);
	}

	free(testcases);

	return 0;
}