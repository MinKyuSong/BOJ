#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Data
{
	int nAge;
	int nOrder;
	string szName;
}Data;
bool cmp(Data& a, Data& b)
{
	if (a.nAge < b.nAge)
		return true;
	else if (a.nAge == b.nAge)
		if (a.nOrder < b.nOrder)
			return true;
	return false;
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<Data>vData(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vData[i].nAge >> vData[i].szName;
		vData[i].nOrder = i;
	}
	sort(vData.begin(), vData.end(), cmp);
	for (int i = 0; i < N; i++)
	{
		cout << vData[i].nAge << " " << vData[i].szName << "\n";
	}
	return 0;
}