#include<iostream>
#include<string.h>
#include<string>
#include<stack>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	stack<int> stackNum;

	for (int i = 0; i < N; i++)
	{
		string szInput;
		cin >> szInput;
		if (strcmp("push", szInput.c_str()) == 0)
		{
			int n;
			cin >> n;
			stackNum.push(n);
		}
		else if (strcmp("pop", szInput.c_str()) == 0)
		{
			if (stackNum.empty())
				cout << -1 << endl;
			else
			{
				cout << stackNum.top() << endl;
				stackNum.pop();
			}
		}
		else if (strcmp("size", szInput.c_str()) == 0)
		{
			cout << stackNum.size() << endl;
		}
		else if (strcmp("empty", szInput.c_str()) == 0)
		{
			if (stackNum.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (strcmp("top", szInput.c_str()) == 0)
		{
			if (stackNum.empty())
				cout << -1 << endl;
			else
			{
				cout << stackNum.top() << endl;
			}
		}
	}

	return 0;
}