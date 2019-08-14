#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
	int nPipe(0);
	int nRes(0);
	char *szInput=new char[100001];
	cin >> szInput;
	for (int i = 0; szInput[i] != 0; i++)
	{
		if (szInput[i] == '(')
		{
			nPipe++;
		}
		else
		{
			nPipe--;
			if (szInput[i - 1] == '(')
				nRes += nPipe;
			else
				nRes++;
		}
	}
	delete[] szInput;
	cout << nRes << endl;
	return 0;
}