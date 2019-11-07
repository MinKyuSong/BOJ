#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	string szInput;
	cin >> szInput;

	vector<string> vszArr;
	for (int i = 0; i < szInput.length(); i++)
	{
		vszArr.push_back(szInput.substr(i, szInput.length() - i));
	}

	sort(vszArr.begin(), vszArr.end());

	for (int i = 0; i < vszArr.size(); i++)
		cout << vszArr[i] << endl;
	return 0;
}