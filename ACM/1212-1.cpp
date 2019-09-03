#include<iostream>
#include<string>
using namespace std;

string binTable[] = { "000","001","010","011","100","101","110","111" };

int main(void)
{
	string szInput;
	cin >> szInput;
	if (szInput.compare("0") == 0)
	{
		cout << 0 << endl;
	}
	string szBinary;
	for (int i = 0; i < szInput.length(); i++)
	{
		int digit = szInput[i] - '0';
		szBinary.append(binTable[digit]);
	}
	for(int i=0;i<szBinary.length();i++)
		if (szBinary[i] != '0')
		{
			cout << szBinary.substr(i, szBinary.length() - i) << endl;
			break;
		}

	return 0;
}