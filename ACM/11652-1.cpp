#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<long long> vNums(N);
	for (int i = 0; i < N; i++)
		cin >> vNums[i];
	sort(vNums.begin(), vNums.end());
	
	int max = 1;
	int count = 1;
	int idx = 0;
	for (int i = 1; i < N; i++)
	{
		if (vNums[i - 1] == vNums[i])
		{
			count++;
		}
		else
		{
			if (count > max)
			{
				max = count;
				idx = i - 1;
			}
			count = 1;
		}
	}
	if (count > max)
	{
		max = count;
		idx = N - 1;
	}
	cout << vNums[idx] << endl;
	return 0;
}