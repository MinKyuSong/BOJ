#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Person 
{
	int nAge;
	char szName[101];
	int nOrder;
}Person;

bool cmp(Person a, Person b)
{
	if (a.nAge < b.nAge)
		return true;
	else if (a.nAge == b.nAge)
		return (a.nOrder < b.nOrder);
	else
		return false;
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int nInput;
	cin >> nInput;

	vector<Person> People(nInput);
	for (int i = 0; i < nInput; i++)
	{
		cin >> People[i].nAge >> People[i].szName;
		People[i].nOrder = i;
	}
	sort(People.begin(), People.end(), cmp);
	for (int i = 0; i < nInput; i++)
	{
		cout << People[i].nAge << ' ' << People[i].szName << '\n';
	}
	return 0;
}