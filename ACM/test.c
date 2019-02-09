#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    char s[101];
    scanf("%[^\n]",s);
    printf("%s\n",s);

    return 0;
}