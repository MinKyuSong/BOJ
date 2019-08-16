#include<cstdio>

using namespace std;

int main(void)
{
	char szInput[101];
	char szOut[101];
	fgets(szInput, sizeof(szInput), stdin);

	int i = 0;
	while (szInput[i] != '\0' && szInput[i] != '\n')
	{
		if (szInput[i] >= 'a' && szInput[i] <= 'z')
		{
			szOut[i] = 'a' + (szInput[i]-'a' + 13)%26;
		}
		else if (szInput[i] >= 'A' && szInput[i] <= 'Z')
		{
			szOut[i] = 'A' + (szInput[i]-'A' + 13) % 26;
		}
		else
			szOut[i] = szInput[i];
		i++;
	}
	szOut[i] = 0;
	printf("%s\n", szOut);
	return 0;
}