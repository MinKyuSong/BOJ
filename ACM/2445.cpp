#include <iostream>

using namespace std;

int main(void)
{
	int nInput;
	cin >> nInput;

	for (int i = 1; i < 2 * nInput; i++)
	{
		if (i < nInput)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << "*";
			}
			for (int k=1;k<=2*(nInput-i);k++)
			{
				cout << " ";
			}
			for (int j = 1; j <= i; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		else if (i == nInput)
		{
			for (int j = 1; j <= 2 * nInput; j++)
				cout << "*";
			cout << endl;
		}
		else
		{
			for (int j = 1; j <= 2*nInput -i; j++)
			{
				cout << "*";
			}
			for (int k = 1; k <= 2 * (i - nInput); k++)
			{
				cout << " ";
			}
			for (int j = 1; j <= 2 * nInput - i; j++)
			{
				cout << "*";
			}
			cout << endl;
		}

	}
	return 0;
}