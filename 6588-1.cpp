#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

bool net[1000001];

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	memset(net, true, 1000001);
	net[2] = true;
	vector<int>vPrime;
	for (int i = 2; i <= 1000000; i++)
	{
		if (net[i])
		{
			vPrime.push_back(i);
			for (int j = i * 2; j <= 1000000; j += i)
				net[j] = false;
		}
	}
	int nInput;
	cin >> nInput;
	while (nInput > 0)
	{
		for (int i = 0; i < vPrime.size(); i++)
		{
			if (net[nInput - vPrime[i]])
			{
				cout << nInput << " = " << vPrime[i] << " + " << nInput - vPrime[i] << "\n";
				break;
			}
		}
		cin >> nInput;
	}
	return 0;
}