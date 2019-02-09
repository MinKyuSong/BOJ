#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
	int arrResult[256];
	char arrInput[101];

	cin >> arrInput;
	int nLen = strlen(arrInput);
	for (int i = 0; i < 256; i++)
		arrResult[i] = -1;
	for (int i = 0; i < nLen; i++)
	{
		char temp = arrInput[i];
		if (arrResult[temp] == -1)
			arrResult[temp] = i;
	}
	for (int i = 'a'; i < 'z'; i++)
	{
		cout << arrResult[i] << " ";
	}
	cout << arrResult['z'] << endl;
	return 0;
}