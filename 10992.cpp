#include<iostream>

using namespace std;

int main(void)
{
	int nInput;
	cin >> nInput;
	for (int i = 1; i <= nInput; i++)
	{
		for (int j = i; j < nInput; j++)
			cout << " ";

		if (i == 1 || i == nInput)
		{
			for (int j = 1; j <= 2 * i - 1; j++)
				cout << "*";
		}

		else
		{
			cout << "*";
			for (int j = 1; j <= 2 * (i - 1) - 1; j++)
				cout << " ";
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}