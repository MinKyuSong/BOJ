#include<iostream>
#include<string>

using namespace std;

int makeOcta(const string &src)
{
	int nTemp = 0;
	nTemp += (src[0]-'0') * 4;
	nTemp += (src[1] - '0') * 2;
	nTemp += (src[2] - '0');
	return nTemp;
}

int main(void)
{
	string szBuffer, szInput, szResult;

	cin >> szBuffer;

	int nLen = szBuffer.length();
	int nTemp = nLen % 3;

	if (nTemp != 0)
	{
		while (nTemp < 3)
		{
			szInput.push_back('0');
			nTemp++;
		}
	}
	szInput.append(szBuffer.begin(), szBuffer.end());

	nLen = szInput.length();
	for (int i = 0; i < nLen; i += 3)
	{
		int nResult = makeOcta(szInput.substr(i,3));
		szResult.push_back('0' + nResult);
	}

	cout << szResult << endl;

	return 0;
}