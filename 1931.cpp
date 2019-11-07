#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct con
{
	int start;
	int end;
}cons;

bool cmp(const con &a, const con &b)
{
	if (a.end == b.end)
		return (a.start < b.start);
	else
		return (a.end < b.end);
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int nResult = 0, N, now=0;
	cin >> N;

	vector<con> vCons(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vCons[i].start >> vCons[i].end;
	}

	sort(vCons.begin(), vCons.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		if (now <= vCons[i].start)
		{
			now = vCons[i].end;
			nResult++;
		}
	}

	cout << nResult << endl;
	return 0;
}