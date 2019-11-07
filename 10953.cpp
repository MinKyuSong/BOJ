#include<iostream>

using namespace std;

int main(void)
{
	int nTry;
	cin >> nTry;
	while (nTry--)
	{
		int a, b;
		char c;
		cin >> a>>c>> b;
		cout << a + b << endl;
	}
	return 0;
}