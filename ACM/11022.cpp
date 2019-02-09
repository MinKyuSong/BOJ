#include<iostream>

using namespace std;

int main(void)
{
	int nTry, i = 1;
	cin >> nTry;
	while (nTry--)
	{
		int a, b;
		cin >> a >> b;
		cout << "Case #" << i++ << ": " << a << " + " << b << " = " << a + b << endl;
	}
	return 0;
}