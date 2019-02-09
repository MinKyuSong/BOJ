#include <iostream>

using namespace std;

int main(void)
{
	int nInput;
	cin >> nInput;

	for (int i = 1; i <= nInput; i++)
	{
		for (int j = 0; j < nInput - i; j++)
			cout << " ";
		for (int j = 1; j < i; j++)
			cout << "* ";
		cout << "*" << endl;
	}
	return 0;
}