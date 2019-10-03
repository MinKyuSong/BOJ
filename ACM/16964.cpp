#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> vSeq;
vector<int> vVisit;
bool visit[100001];
int order[100001];

void DFS(int now, const vector<vector<int>>& vGraph)
{
	vVisit.push_back(now);
	visit[now] = true;
	for (int next : vGraph[now])
	{
		if (!visit[next])
			DFS(next, vGraph);
	}
	return;
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	vector<vector<int>> vGraph(N + 1);
	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		vGraph[a].push_back(b);
		vGraph[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		vSeq.push_back(a);
		order[a] = i;
	}
	for (int i = 1; i <= N; i++)
		sort(vGraph[i].begin(), vGraph[i].end(),
			[&](const int& l, const int& r) {
				return order[l] < order[r];
			}
	);
	DFS(1,vGraph);
	bool check = true;
	for (int i = 0; i < N; i++)
	{
		if (vSeq[i] != vVisit[i])
		{
			check = false;
			break;
		}
	}

	if (check)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}