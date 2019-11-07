#include<iostream>
using namespace std;

int main(void)
{
	static bool sieve[1000001];

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	sieve[0] = sieve[1] = true;

	for (int i = 2; i*i <= 1000000; i++)
	{
		if (sieve[i] == false)
		{
			for (int j = i + i; j <= 1000000; j += i)
			{
				sieve[j] = true;
			}
		}
	}

	int nInput;
	cin >> nInput;
	while (nInput > 0)
	{
		bool flag = true;
		for (int i = 3; i <= (nInput / 2); i += 2)
		{
			if (sieve[i] == false && sieve[nInput - i] == false)
			{
				cout << nInput << " = " << i << " + " << nInput - i << '\n';
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "Goldbach's conjecture is wrong." << '\n';
		cin >> nInput;
	}

	return 0;
}