#include<iostream>
#include<vector>
using namespace std;

int nResult;
int mate[100001];
int group[100001];
bool check[100001];
int g = 0;
void DFS(int node)
{
	vector<int> vSearch;
	group[node] = g;
	vSearch.push_back(node);

	int next = mate[node];
	while (group[next] == 0)
	{
		group[next] = g;
		vSearch.push_back(next);
		next = mate[next];
	}
	int knot = next;
	if (g == group[knot])
	{
		while (vSearch.back() != knot)
			vSearch.pop_back();
		vSearch.pop_back();
		nResult += vSearch.size();
	}
	else
		nResult += vSearch.size();
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> mate[i];
			group[i] = 0;
		}
		nResult = 0;
		g = 0;
		for (int i = 1; i <= N; i++)
		{
			if (group[i] == 0)
			{
				g+=1;
				DFS(i);
			}
		}
		cout << nResult << endl;
	}
	return 0;
}