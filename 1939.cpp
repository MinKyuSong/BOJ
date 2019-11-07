#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> vIsland[10001];
bool visit[10001];
int n, m;
int src, dest;
bool go(int node, int limit) 
{
	if (visit[node])
	{
		return false;
	}
	visit[node] = true;
	if (node == dest)
	{
		return true;
	}
	for (auto& p : vIsland[node])
	{
		int next = p.first;
		int cost = p.second;
		if (cost >= limit)
		{
			if (go(next, limit)) 
			{
				return true;
			}
		}
	}
	return false;
}
int main() 
{
	cin >> n >> m;
	while (m--) 
	{
		int A, B, C;
		cin>>A>>B>>C;
		vIsland[A].push_back(make_pair(B, C));
		vIsland[B].push_back(make_pair(A, C));
	}
	cin >> src >> dest;
	
	int left = 1;
	int right = 1000000000;
	int ans = 0;
	while (left <= right) 
	{
		int mid = left + (right - left) / 2;
		for (int i = 0; i < 10001; i++)
			visit[i] = false;
		if (go(src, mid)) 
		{
			ans = mid;
			left = mid + 1;
		}
		else 
		{
			right = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}