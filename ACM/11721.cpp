#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s;
	int i = 0;

	getline(cin, s);
	
	for (auto &e : s)
	{
		cout << e;
		i++;

		if (i == 10)
		{
			cout << endl;
			i = 0;
		}
	}
	
	return 0;
}