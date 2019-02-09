#include<iostream>

using namespace std;

int main(void)
{
	int nInput;

	cin >> nInput;

	for (int i = 0; i < nInput; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int k = nInput-i; k > 0; k--)
		{
			cout << "*";
		}
		cout << endl;
	}
}
