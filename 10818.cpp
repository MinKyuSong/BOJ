#include<iostream>

using namespace std;

int main(void)
{
	int nInput;
	int min = 1000000;
	int max = -1000000;

	cin >> nInput;
	while (nInput--)
	{
		int temp;
		cin >> temp;
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
	}
	cout << min << ' ' << max << endl;

	return 0;
}