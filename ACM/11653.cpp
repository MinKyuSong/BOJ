#include<iostream>
using namespace std;

int main(void)
{
	int nInput;
	cin >> nInput;

	for (int i = 2; i*i <= nInput; i++)
	{
		while (nInput%i == 0)
		{
			cout << i << endl;
			nInput /= i;
		}
	}
	if (nInput > 1)
		cout << nInput << endl;
	return 0;
}