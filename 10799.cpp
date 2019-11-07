#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
	string cInput;
	int nLen,nResult=0;
	stack<int> index;

	cin >> cInput;
	nLen = cInput.length();

	for (int i = 0; i < nLen; i++)
	{
		if (cInput[i] == '(')
			index.push(i);
		else
		{
			int temp=index.top();
			index.pop();
			if ((i - temp) == 1)
			{
				nResult += index.size();
			}
			else
			{
				nResult++;
			}
		}
	}

	cout << nResult << endl;
	return 0;
}