#include<iostream>

using namespace std;

int main(void)
{
	int nInput;
	cin >> nInput;

	for (int i = 1; i < 10; i++)
	{
		cout << nInput << " * " << i << " = " << nInput * i << endl;
	}
	return 0;
}