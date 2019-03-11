#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int nInput;
	cin >> nInput;

	vector<int> viInputs(nInput);

	for (int i = 0; i < nInput; i++)
	{
		cin >> viInputs[i];
	}

	sort(viInputs.begin(), viInputs.end());

	for (int i = 0; i < nInput; i++)
	{
		cout << viInputs[i] << '\n';
	}

	return 0;
}