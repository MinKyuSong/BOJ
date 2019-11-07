#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	queue<int> round;
	int n, m, idx = 0;

	cin >> n >> m;
	int *nResult = new int[n];

	for (int i = 1; i <= n; i++)
	{
		round.push(i);
	}
	while (!round.empty())
	{
		for (int i = 1; i < m; i++)
		{
			int temp = round.front();
			round.pop();
			round.push(temp);
		}
		nResult[idx]=round.front();
		round.pop();
		idx++;
	}

	cout << "<";
	for (int i = 0; i < n-1; i++)
		cout << nResult[i] << ", ";
	cout << nResult[n-1] << ">" << endl;
	return 0;
}