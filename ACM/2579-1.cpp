#include<iostream>

using namespace std;

int n;
static int nSteps[301];
static int nScores[301];

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> nSteps[i];

	nScores[1] = nSteps[1];
	nScores[2] = nSteps[2] + nScores[1];
	for (int i = 3; i <= n; i++)
	{
		nScores[i] = nSteps[i] +
			(nScores[i - 3] + nSteps[i - 1] > nScores[i - 2] ?
				nScores[i - 3] + nSteps[i - 1] : nScores[i - 2]);
	}

	cout << nScores[n] << endl;
	return 0;
}