#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct loc
{
	int x, y;
}loc;

bool compare(const loc& a, const loc& b)
{
	if (a.y < b.y)
		return true;
	else if (a.y == b.y)
		return (a.x < b.x);
	else
		return false;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int nInput;
	cin >> nInput;

	vector<loc>vLocs(nInput);

	for (int i = 0; i < nInput; i++)
		cin >> vLocs[i].x >> vLocs[i].y;

	sort(vLocs.begin(), vLocs.end(), compare);

	for (int i = 0; i < nInput; i++)
		cout << vLocs[i].x << ' ' << vLocs[i].y << '\n';

	return 0;
}