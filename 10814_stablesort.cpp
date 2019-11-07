#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int nInput;
	cin >> nInput;

	typedef pair<int, char*> person;
	vector<person> vPeople(nInput);

	for (int i = 0; i < nInput; i++)
	{
		vPeople[i].second = new char[101];
		cin >> vPeople[i].first >> vPeople[i].second;
	}

	stable_sort(vPeople.begin(), vPeople.end());

	for (int i = 0; i < nInput; i++)
	{
		cout << vPeople[i].first << " " << vPeople[i].second << '\n';
		delete vPeople[i].second;
	}
	return 0;
}