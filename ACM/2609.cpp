#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b, int g)
{
	return (a / g)*(b / g) * g;
}

int main(void)
{
	int a, b, g, l;
	cin >> a >> b;

	g = gcd(a, b);
	l = lcm(a, b, g);

	cout << g << endl;
	cout << l << endl;


	return 0;
}