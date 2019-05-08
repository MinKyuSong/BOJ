#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	vector<int>positive;
	vector<int>negative;
	vector<int>zero;
	vector<int>one;

	int n;
	cin >> n;
	while (n--)
	{
		int temp;
		cin >> temp;
		if (temp > 1)
			positive.push_back(temp);
		else if (temp == 1)
			one.push_back(temp);
		else if (temp == 0)
			zero.push_back(temp);
		else
			negative.push_back(temp);
	}

	sort(negative.begin(), negative.end());
	sort(positive.begin(), positive.end());
	reverse(positive.begin(), positive.end());

	if (positive.size() % 2 == 1)
		positive.push_back(1);
	if (negative.size() % 2 == 1)
		if (zero.size() != 0)
			negative.push_back(0);
		else
			negative.push_back(1);

	int nResult = 0;
	for (unsigned int i = 0; i < positive.size(); i += 2)
	{
		nResult += (positive[i] * positive[i + 1]);
	}
	for (unsigned int i = 0; i < negative.size(); i += 2)
	{
		nResult += (negative[i] * negative[i + 1]);
	}
	nResult += one.size();
	cout << nResult << endl;

	return 0;
}