#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	char szSrc[102];
	char szDst[102];
	int i;
	fgets(szSrc,102,stdin);

	for (i = 0; szSrc[i]!='\n'; i++)
	{
		if (szSrc[i] == ' ')
			szDst[i] = szSrc[i];
		else if (szSrc[i] >= 'A' && szSrc[i] <= 'Z')
		{
			int temp = szSrc[i] + 13;
			if (temp > 'Z')
				temp = temp - 26;
			szDst[i] = char(temp);
		}
		else if (szSrc[i] >= 'a'&&szSrc[i] <= 'z')
		{
			int temp = szSrc[i] + 13;
			if (temp > 'z')
				temp = temp - 26;
			szDst[i] = char(temp);
		}
		else
			szDst[i] = szSrc[i];
	}
	szDst[i] = '\0';
	cout << szDst << endl;
	return 0;
}