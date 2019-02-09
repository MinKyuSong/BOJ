#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;
void clear_stdin()
{
	int ch;

	while ((ch = getchar()) != EOF && ch != '\n') {};
}

int main(void)
{
	char cInput;
	int nTry, nCount;
	bool flag;

	scanf("%d", &nTry);
	clear_stdin();
	while (nTry--)
	{
		flag = true;
		nCount = 0;
		while (true)
		{
			scanf("%c", &cInput);
			if (cInput == '(')
				nCount++;
			else if (cInput == ')')
				nCount--;
			else if (cInput == '\n' || cInput == EOF)
				break;
			if (nCount < 0)
			{
				flag = false;
				break;
			}
		}
		if (nCount != 0 || flag == false)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		if (cInput != '\n' && cInput != EOF)
			clear_stdin();
	}
	
	return 0;
}