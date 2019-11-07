#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef struct edge
{
	int to;
	int dist;
	edge(int a, int b) :to(a), dist(b) {}
}edge;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<edge> vTree[100001];
	bool check[100001];
	int dist[100001];

	for (int i = 1; i <= N; i++)
	{
		int x, y, z;
		cin >> x;
		
		while (1)
		{
			cin >> y;
			if (y == -1) break;
			cin >> z;
			vTree[x].push_back(edge(y, z));
			vTree[y].push_back(edge(x, z));
		}
		check[i] = false;
	}

	queue<int> qSearch;
	qSearch.push(1);
	check[1] = true;
	dist[1] = 0;
	while (!qSearch.empty())
	{
		int nTemp;
		nTemp = qSearch.front(); qSearch.pop();

		for (unsigned int i = 0; i < vTree[nTemp].size(); i++)
		{
			if (check[vTree[nTemp][i].to]) continue;
			qSearch.push(vTree[nTemp][i].to);
			check[vTree[nTemp][i].to] = true;
			dist[vTree[nTemp][i].to] = dist[nTemp]+vTree[nTemp][i].dist;
		}
	}

	int far = 0; int farpoint = 1;
	for (int i = 1; i <= N; i++)
	{
		check[i] = false;
		if (far < dist[i])
		{
			far = dist[i];
			farpoint = i;
		}
	}

	qSearch.push(farpoint);
	check[farpoint] = true;
	dist[farpoint] = 0;
	while (!qSearch.empty())
	{
		int nTemp;
		nTemp = qSearch.front(); qSearch.pop();

		for (unsigned int i = 0; i < vTree[nTemp].size(); i++)
		{
			if (check[vTree[nTemp][i].to]) continue;
			qSearch.push(vTree[nTemp][i].to);
			check[vTree[nTemp][i].to] = true;
			dist[vTree[nTemp][i].to] = dist[nTemp] + vTree[nTemp][i].dist;
		}
	}
	far = 0;
	for (int i = 1; i <= N; i++)
	{
		if (far < dist[i])
		{
			far = dist[i];
		}
	}
	cout << far << '\n';
	return 0;
}