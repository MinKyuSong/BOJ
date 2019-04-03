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
		if (nTemp == 1)
			nOnes++;
		else if (nTemp > 0)
			vPositive.push_back(nTemp);
		else if (nTemp < 0)
			vNegative.push_back(nTemp);
		else
			nZeroes++;
	}

	sort(vPositive.begin(), vPositive.end());
	sort(vNegative.begin(), vNegative.end());
	reverse(vPositive.begin(), vPositive.end());

	if (vPositive.size() % 2 == 1)
		vPositive.push_back(1);
	if (vNegative.size() % 2 == 1)
	{
		if (nZeroes > 0)
			vNegative.push_back(0);
		else
			vNegative.push_back(1);
	}
	nResult += nOnes;
	for (unsigned int i = 0; i < vPositive.size(); i += 2)
	{
		nResult += (vPositive[i] * vPositive[i + 1]);
	}
	for (unsigned int i = 0; i < vNegative.size(); i += 2)
	{
		nResult += (vNegative[i] * vNegative[i + 1]);
	}

	cout << nResult << endl;
	return 0;
}