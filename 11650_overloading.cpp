#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct loc
{
	int x;
	int y;
	bool operator <(const loc &a) const
	{
		if (x < a.x)
			return true;
		else if (x == a.x)
			return (y < a.y);
		else
			return false;
	}
} loc;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int nInput;
	cin >> nInput;

	vector<loc>vLocs(nInput);

	for (int i = 0; i < nInput; i++)
		cin >> vLocs[i].x >> vLocs[i].y;

	sort(vLocs.begin(), vLocs.end());

	for (int i = 0; i < nInput; i++)
		cout << vLocs[i].x << " " << vLocs[i].y << "\n";

	return 0;
}