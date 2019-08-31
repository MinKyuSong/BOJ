#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string szInput;
	int B;
	cin >> szInput >> B;

	long long sum = 0;
	for (int i = 0; i < szInput.length(); i++)
	{
		sum *= B;
		if (szInput[i] >= 'A')
			sum += (10 + szInput[i] - 'A');
		else
			sum += (szInput[i] - '0');
	}
	cout << sum << endl;
	return 0;
}