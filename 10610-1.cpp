#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	string s;
	cin >> s;

	int nSum = 0;
	for (int i = 0; i < s.size(); i++)
		nSum += s[i] - '0';

	sort(s.begin(), s.end());
	if (nSum % 3 == 0 && s[0] == '0')
	{
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}