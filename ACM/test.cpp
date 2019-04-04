#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	vector<int> vPositive;
	vector<int> vNegative;
	int nOnes = 0, nZeroes = 0, nResult = 0, nCount;

	cin >> nCount;

	for (int i = 0; i < nCount; i++)
	{
		int nTemp;
		cin >> nTemp;
		if (nTemp > 1)
			vPositive.push_back(nTemp);
		else if (nTemp < 0)
			vNegative.push_back(nTemp);
		else if (nTemp == 0)
			nZeroes++;
		else
			nOnes++;
	}

	sort(vPositive.begin(), vPositive.end());
	sort(vNegative.begin(), vNegative.end());
	reverse(vNegative.begin(), vNegative.end());

	int nFirst, nSecond;
	while (!vPositive.empty())
	{
		nFirst = vPositive.back();
		vPositive.pop_back();
		if (vPositive.empty())
		{
			nSecond = 1;
		}
		else
		{
			nSecond = vPositive.back();
			vPositive.pop_back();
		}
		nResult += (nFirst*nSecond);
	}
	while (!vNegative.empty())
	{
		nFirst = vNegative.back();
		vNegative.pop_back();
		if (vPositive.empty() && nZeroes > 0)
		{
			nSecond = 0;
			nZeroes--;
		}
		else if (vPositive.empty())
		{
			nSecond = 1;
		}
		else
		{
			nSecond = vPositive.back();
			vPositive.pop_back();
		}
		nResult += (nFirst*nSecond);
	}
	nResult += nOnes;
	cout << nResult << endl;
	return 0;
}