#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long long pay[100001];

int main(void)
{
	long long i, m, n, temp;
	long long	max = 0;

	scanf("%lld %lld", &n, &m);

	pay[0] = 0;
	
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &temp);
		pay[i] = temp + pay[i - 1];
		if ((i >= m) && (max < pay[i] - pay[i - m]))
			max = pay[i] - pay[i - m];
	}

	printf("%lld\n",max);

	return 0;
}