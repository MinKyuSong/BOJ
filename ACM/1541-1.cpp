#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

int main(void)
{
	bool flag = true;
	int temp = 0;
	vector<int> positive, negative;
	string s;
	cin >> s;
	for (auto &a : s)
	{
		if (a >= '0'&&a <= '9')
		{
			temp *= 10;
			temp += a - '0';
		}
		else
		{
			if (flag)
			{
				positive.push_back(temp);
			}
			else
			{
				negative.push_back(temp);
			}
			if (a == '-')
			{
				flag = false;
			}
			temp = 0;
		}
	}
	if (flag)
	{
		positive.push_back(temp);
	}
	else
	{
		negative.push_back(temp);
	}
	int result = 0;
	for (auto &a : positive)
		result += a;
	for (auto &a : negative)
		result -= a;

	cout << result << endl;

	return 0;
}