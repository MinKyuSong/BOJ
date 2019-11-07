#include<cstdio>
#include<cstring>
using namespace std;

char szInput[5001];
static int nArr[5001];
int main(void)
{
	scanf("%s", szInput);
	int len = strlen(szInput);
	nArr[0] = 1;
	for (int i = 0,j=1; i < len; i++,j++)
	{
		int t1 = szInput[i] - '0';
		int t2 = 0;

		if (t1 > 0)
			nArr[j] = nArr[j - 1];
		if (i > 0)
			t2 = szInput[i-1] - '0';
		if (t2 < 3 && t2>0 && i > 0)
		{
			int t3 = 10 * t2 + t1;
			if (t3 < 27)
				nArr[j] += nArr[j - 2];
		}
		nArr[j] %= 1000000;
	}

	printf("%d\n", nArr[len]);
	return 0;
}