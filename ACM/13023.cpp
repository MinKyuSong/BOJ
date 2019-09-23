#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int N, M;
vector<int> g[2000];
vector<pair<int, int>> edge;
bool gt[2000][2000];
int etable[2000];
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		gt[a][b] = true;
		gt[b][a] = true;
		edge.push_back(make_pair(a, b));
		edge.push_back(make_pair(b, a));
		g[a].push_back(b);
		g[b].push_back(a);
	}
	M *= 2;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int A = edge[i].first;
			int B = edge[i].second;
			int C = edge[j].first;
			int D = edge[j].second;
			
			if (A == B || A == C || A == D || B == C || B == D || C == D)
				continue;
			if (!gt[B][C])
				continue;
			for (int E : g[D])
			{
				if (E == A || E == B || E == C || E == D)
					continue;
				cout << 1 << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;
	return 0;
}