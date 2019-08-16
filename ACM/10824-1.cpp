#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	long long A(0), B(0);
	for (int i = 0; i < a.length(); i++)
	{
		A *= 10;
		A += a[i] - '0';
	}
	for (int i = 0; i < b.length(); i++)
	{
		A *= 10;
		A += b[i] - '0';
	}
	for (int i = 0; i < c.length(); i++)
	{
		B *= 10;
		B += c[i] - '0';
	}for (int i = 0; i < d.length(); i++)
	{
		B *= 10;
		B += d[i] - '0';
	}
	cout << A + B << endl;
	return 0;
}