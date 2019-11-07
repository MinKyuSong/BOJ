#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<tuple>
using namespace std;
typedef struct Data
{
	string szName;
	int lit;
	int eng;
	int math;
}Data;
bool cmp(Data& a, Data& b)
{
	return make_tuple(-a.lit, a.eng, -a.math, a.szName) <
		make_tuple(-b.lit, b.eng, -b.math, b.szName);
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<Data> vData(N);
	for (int i = 0; i < N; i++)
		cin >> vData[i].szName >> vData[i].lit >> vData[i].eng >> vData[i].math;
	sort(vData.begin(), vData.end(), cmp);
	for (int i = 0; i < N; i++)
		cout << vData[i].szName << "\n";
	return 0;
}