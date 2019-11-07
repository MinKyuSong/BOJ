#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
int parent[100001];
vector<int> vSeq;

bool BFS(const vector<vector<int>>& vGraph)
{
	queue<int> q;
	q.push(1);
	parent[1] = -1;
	bool check = true;
	for (int i = 0; i < vSeq.size(); i++)
	{
		int now = vSeq[i];
		int count=0;
		int tsize = q.size();
		q.pop();
		
		for (int next : vGraph[now])
		{
			if (parent[next] == 0)
			{
				q.push(next);
				parent[next] = now;
				count++;
			}
		}
		for (int j=i+tsize;j<i+tsize+count;j++)
		{
			if (parent[vSeq[j]] != now)
			{
				check = false;
				break;
			}
		}
		if (!check)
			break;
	}
	return check;
}
int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> N;
	vector<vector<int>> vGraph(N+1);
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
	}
	
	bool check = BFS(vGraph);

	if (check)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}