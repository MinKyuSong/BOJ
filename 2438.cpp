#include<iostream>

using namespace std;

int main(void)
{
	int nInput;

	cin >> nInput;

	for (int i = 1; i <= nInput; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}