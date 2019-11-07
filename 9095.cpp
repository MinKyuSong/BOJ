#include<iostream>

using namespace std;

int main(void)
{
	int nTry;
	static int arrResult[11];
	
	cin >> nTry;

	arrResult[1] = 1; arrResult[2] = 2; arrResult[3] = 4;
	while (nTry--)
	{
		int nTarget;
		cin >> nTarget;

		for (int i = 4; i <= nTarget; i++)
		{
			if (arrResult[i] == 0)
				arrResult[i] = (
					arrResult[i - 1] +
					arrResult[i - 2] +
					arrResult[i - 3]
					);
		}
		cout << arrResult[nTarget] << endl;
	}

	return 0;
}