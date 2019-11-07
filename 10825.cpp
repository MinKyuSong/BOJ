#include<iostream>
#include<tuple>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Person
{
	string szName;
	int kor, eng, math;
}Person;
bool cmp(Person &a, Person &b)
{
	return make_tuple(-a.kor, a.eng, -a.math, a.szName) < make_tuple(-b.kor, b.eng, -b.math, b.szName);
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int nInput;
	cin >> nInput;

	vector<Person> vScore(nInput);

	for (int i = 0; i < nInput; i++)
	{
		cin >> vScore[i].szName >> vScore[i].kor >> vScore[i].eng >> vScore[i].math;
	}

	sort(vScore.begin(), vScore.end(), cmp);

	for (int i = 0; i < nInput; i++)
	{
		cout << vScore[i].szName << '\n';
	}
	return 0;
}