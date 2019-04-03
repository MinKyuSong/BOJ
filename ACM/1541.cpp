#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void)
{
	string sInput;
	cin >> sInput;

	vector<int>vPositive;
	vector<int>vNegative;
	unsigned int i = 0;
	int nTemp = 0;

	bool flag = true;
	while (i < sInput.size())
	{
		nTemp = 0;
		if (sInput[i] == '-'||sInput[i]=='+')
		{
			if(sInput[i]=='-')
				flag = false;
			i++;
		}
		
		while (sInput[i] >= '0'&&sInput[i] <= '9')
		{
			nTemp *= 10;
			nTemp += (sInput[i++] - '0');
		}

		if (flag)
			vPositive.push_back(nTemp);
		else
			vNegative.push_back(nTemp);
	}

	int nResult = 0;
	for (auto &a : vPositive)
		nResult += a;
	for (auto &a : vNegative)
		nResult -= a;
	cout << nResult << endl;

	return 0;
}