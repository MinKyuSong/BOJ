#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<int> vTree[100001];
	bool check[100001];
	int parent[100001];

	for (int i = 2; i <= N; i++)
	{
		int x, y;
		cin >> x >> y;
		vTree[x].push_back(y);
		vTree[y].push_back(x);
		check[i] = false;
	}
	
	queue<int> qSearch;
	qSearch.push(1);
	check[1] = true;

	while (!qSearch.empty())
	{
		int nTemp;
		nTemp = qSearch.front(); qSearch.pop();
		
		for (unsigned int i = 0; i < vTree[nTemp].size(); i++)
		{
			if (check[vTree[nTemp][i]]) continue;
			qSearch.push(vTree[nTemp][i]);
			check[vTree[nTemp][i]] = true;
			parent[vTree[nTemp][i]] = nTemp;
		}
	}

	for (int i = 2; i <= N; i++)
		cout << parent[i] << endl;

	return 0;
}