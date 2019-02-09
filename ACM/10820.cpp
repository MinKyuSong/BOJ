#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


int main()
{
	char arr[102];
	while (fgets(arr, sizeof(arr), stdin) != NULL)
	{

		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;

		int len = strlen(arr);

		for (int i = 0; i < len; i++)
		{
			if (97 <= arr[i] && arr[i] <= 122)
				a++;
			else if (65 <= arr[i] && arr[i] <= 90)
				b++;
			else if (48 <= arr[i] && arr[i] <= 57)
				c++;
			else if ((arr[i]) == 32)
				d++;
		}

		printf("%d %d %d %d\n", a, b, c, d);
	}
	return 0;
}