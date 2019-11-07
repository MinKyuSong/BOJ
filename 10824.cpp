#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string A, B, C, D;

	cin >> A >> B >> C >> D;

	string AB = A + B;
	string CD = C + D;

	long long llAB = stoll(AB);
	long long llCD = stoll(CD);

	cout << llAB + llCD << endl;

	return 0;
}