#include<iostream>
#include<vector>
using namespace std;

int group[20001];
vector<vector<int>> node(20001);

bool dfs(int root, int p_group)
{
	group[root] = p_group;
	bool flag = true;
	for (unsigned int i = 0; i < node[root].size(); i++)
	{
		if (group[node[root][i]] == p_group)
		{
			return false;
		}
		if(group[node[root][i]]==0)
			flag = dfs(node[root][i], 3 - p_group);
		if (!flag)
			break;
	}
	return flag;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	int K;
	cin >> K;
	while (K--)
	{
		int V, E;
		cin >> V >> E;
		for (int i = 1; i <= 20000; i++)
		{
			node[i].clear();
			group[i] = 0;
		}
		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			node[a].push_back(b);
			node[b].push_back(a);
		}

		bool flag=true;
		for (int i = 1; i <= V; i++)
		{
			if (group[i] == 0)
				flag = dfs(i,1);
			if (!flag)
				break;
		}
		if (flag)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}