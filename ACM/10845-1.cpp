#include<iostream>
#include<string.h>
#include<string>
#include<queue>

using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N;
	cin >> N;
	queue<int> qnRes;
	while (N--)
	{
		string szInput;
		cin >> szInput;
		if (strcmp(szInput.c_str(), "push") == 0)
		{
			int temp;
			cin >> temp;
			qnRes.push(temp);
		}
		else if (strcmp(szInput.c_str(), "pop") == 0)
		{
			if (qnRes.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << qnRes.front() << endl;
				qnRes.pop();
			}
		}
		else if (strcmp(szInput.c_str(), "size") == 0)
		{
			cout << qnRes.size() << endl;
		}
		else if (strcmp(szInput.c_str(), "empty") == 0)
		{
			if (qnRes.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (strcmp(szInput.c_str(), "front") == 0)
		{
			if (qnRes.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << qnRes.front() << endl;
			}
		}
		else if (strcmp(szInput.c_str(), "back") == 0)
		{
			if (qnRes.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << qnRes.back() << endl;
			}
		}
	}
	return 0;
}