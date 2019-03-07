#include<iostream>
#include<string>
using namespace std;

void makeBin(int octa, string& szResult)
{
	int nTemp;
	
	if (octa >= 4)
	{
		szResult.push_back('1');
		octa -= 4;
	}
	else
	{
		if (szResult.length() != 0)
			szResult.push_back('0');
	}

	if (octa >= 2)
	{
		szResult.push_back('1');
		octa -= 2;
	}
	else
	{
		if (szResult.length() != 0)
			szResult.push_back('0');
	}

	if (octa > 0)
	{
		szResult.push_back('1');
	}
	else
	{
		szResult.push_back('0');
	}

	return;
}
int main(void)
{
	string szInput, szResult;

	cin >> szInput;

	int nLen = szInput.length();
	for (int i = 0; i < nLen; i++)
	{
		int octa = szInput[i] - '0';
		makeBin(octa, szResult);
	}
	/*if (szResult.length() == 0)
	{
		szResult.push_back('0');
	}*/
	cout << szResult << endl;

	return 0;
}