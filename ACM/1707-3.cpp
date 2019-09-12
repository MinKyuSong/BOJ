#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int group[20001];

bool DFS(int start, int g, const vector<vector<int>> &vVertex)
{
	group[start] = g;
	bool result = true;
	for (int i = 0; i < vVertex[start].size(); i++)
	{
		if (group[vVertex[start][i]] == g)
			return false;
		if(group[vVertex[start][i]]==0)
			result = DFS(vVertex[start][i], 3 - g, vVertex);
	}
	return result;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int K;
	cin >> K;
	while (K--)
	{
		int V, E;
		cin >> V >> E;
		
		vector<vector<int>> vVertex(V+1);
		for (int i = 1; i <= V; i++)
			group[i] = 0;
		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			vVertex[a].push_back(b);
			vVertex[b].push_back(a);
		}
		bool check = true;
		for (int i = 1; i <= V; i++)
		{
			if (group[i] == 0)
			{
				check = DFS(i, 1, vVertex);
				if (check == false)
					break;
			}
		}
		if (check)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}