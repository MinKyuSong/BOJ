#include<iostream>

using namespace std;

int main(void)
{
	int nInput;

	cin >> nInput;

	for (int i = 0; i < nInput; i++)
	{
		for (int j = nInput-i; j >0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
}