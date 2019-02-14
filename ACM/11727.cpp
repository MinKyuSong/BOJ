#include<iostream>

using namespace std;

int main(void)
{
	int nInput;
	int arrResult[1001];

	cin >> nInput;

	arrResult[0] = 1; arrResult[1] = 1;

	for (int i = 2; i <= nInput; i++)
	{
		arrResult[i] = (arrResult[i - 1] + (2 * arrResult[i - 2])) % 10007;
	}

	cout << arrResult[nInput] << endl;

	return 0;
}