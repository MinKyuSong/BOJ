#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
	stack<char> lstack;
	stack<char> rstack;
	string sInput;
	int nTry;
	char cInput;

	cin >> sInput;
	for (int i = 0,nLen= sInput.length(); i < nLen; i++)
		lstack.push(sInput[i]);

	cin >> nTry;
	while (nTry--)
	{
		cin >> cInput;
		if (cInput == 'L'&&lstack.size() != 0)
		{
			rstack.push(lstack.top());
			lstack.pop();
		}
		else if (cInput == 'D'&&rstack.size()!=0)
		{
			lstack.push(rstack.top());
			rstack.pop();
		}
		else if (cInput == 'B'&&lstack.size() != 0)
		{
			lstack.pop();
		}
		else if (cInput == 'P')
		{
			cin >> cInput;
			lstack.push(cInput);
		}
	}
	while (!lstack.empty())
	{
		rstack.push(lstack.top());
		lstack.pop();
	}
	while (!rstack.empty())
	{
		cout << rstack.top();
		rstack.pop();
	}
	cout << endl;

	return 0;
}