#include<iostream>

using namespace std;

int main(void)
{
	int nInput;

	cin >> nInput;

	for (int i = 1; i <= nInput; i++)
	{
		for (int j = nInput - i; j > 0; j--)
		{
			cout << " ";
		}
		for (int k = 0; k < i; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}