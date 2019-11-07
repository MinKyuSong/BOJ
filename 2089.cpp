#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int nInput;
	string szTemp, szResult;

	cin >> nInput;

	while (nInput != 0 && nInput!=1)
	{
		int nTemp;
		if (nInput < 0)
		{
			nTemp = (-nInput) % 2;
			nInput = (nInput - 1) / -2;
		}
		else
		{
			nTemp = nInput % 2;
			nInput = -(nInput / 2);
		}
		szTemp.push_back(nTemp + '0');
	}
	if(nInput==1|| szTemp.length() == 0)
		szTemp.push_back(nInput + '0');

	while (!szTemp.empty())
	{
		szResult.push_back(szTemp[szTemp.length()-1]);
		szTemp.pop_back();
	}
	cout << szResult << endl;

	return 0;
}