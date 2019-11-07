#include<iostream>
#include<stack>

using namespace std;
int main(void)
{
	int N;
	cin >> N;
	for (int t = 0; t < N; t++)
	{
		stack<int> stkIn;
		char szInputs[51];
		cin >> szInputs;
		for (int i = 0; szInputs[i] != 0; i++)
		{
			if (szInputs[i] == '(')
				stkIn.push(1);
			else
			{
				if (stkIn.empty())
					goto failure;
				else
					stkIn.pop();
			}
		}
		if (stkIn.empty())
		{
			cout << "YES" << endl;
			continue;
		}
	failure:
		cout << "NO" << endl;
	}
}