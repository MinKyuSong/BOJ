#include<iostream>

using namespace std;

int main(void)
{
	int nCountArr[26];
	for (int i = 0; i < 26; i++)
		nCountArr[i] = -1;

	char szInput[101];
	cin >> szInput;

	for (int i = 0; szInput[i] != 0 && szInput[i] != '\n'; i++)
	{
		if (nCountArr[szInput[i] - 'a'] == -1)
		{
			nCountArr[szInput[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < 26; i++)
		cout << nCountArr[i] << ' ';
	cout << endl;

	return 0;
}