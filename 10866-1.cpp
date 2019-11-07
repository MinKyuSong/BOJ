#include<iostream>
#include<string.h>
#include<string>
#include<deque>

using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	deque<int> dqn;
	while (N--)
	{
		string szInput;
		cin >> szInput;

		if (strcmp(szInput.c_str(), "push_front")==0)
		{
			int t;
			cin >> t;
			dqn.push_front(t);
		}
		else if (strcmp(szInput.c_str(), "push_back") == 0)
		{
			int t;
			cin >> t;
			dqn.push_back(t);
		}
		else if (strcmp(szInput.c_str(), "pop_front") == 0)
		{
			if (dqn.empty())
				cout << -1 << endl;
			else
			{
				cout << dqn.front() << endl;
				dqn.pop_front();
			}
		}
		else if (strcmp(szInput.c_str(), "pop_back") == 0)
		{
			if (dqn.empty())
				cout << -1 << endl;
			else
			{
				cout << dqn.back() << endl;
				dqn.pop_back();
			}
		}
		else if (strcmp(szInput.c_str(), "size") == 0)
		{
			cout << dqn.size() << endl;
		}
		else if (strcmp(szInput.c_str(), "empty") == 0)
		{
			if (dqn.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (strcmp(szInput.c_str(), "front") == 0)
		{
			if (dqn.empty())
				cout << -1 << endl;
			else
				cout << dqn.front() << endl;
		}
		else if (strcmp(szInput.c_str(), "back") == 0)
		{
			if (dqn.empty())
				cout << -1 << endl;
			else
				cout << dqn.back() << endl;
		}
	}
	return 0;
}