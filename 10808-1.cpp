#include<iostream>
#include<cstring>
using namespace std;
static int nCountArr[26];
int main(void)
{
	char szInput[101];
	cin >> szInput;
	for (int i = 0; i<strlen(szInput); i++)
		nCountArr[szInput[i]-'a']++;
	for (int i = 0; i < 26; i++)
		cout << nCountArr[i] << ' ';
	cout << endl;
	return 0;
}