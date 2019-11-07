#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
	int arrResult[255] = {0,};
	char arrInput[101];

	cin >> arrInput;
	int nLen = strlen(arrInput);

	for (int i = 0; i < nLen; i++)
	{
		arrResult[arrInput[i]]++;
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << arrResult[i] << " ";
	}
	return 0;
}