#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vGraph(100001);
int parent[100001];

void DFS(int node, int prev)
{
    parent[node] = prev;
    for (int next : vGraph[node])
    {
        if (parent[next] == 0)
            DFS(next, node);
    }
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        vGraph[a].push_back(b);
        vGraph[b].push_back(a);
    }

    DFS(1, 1);
    for (int i = 2; i <= N; i++)
        cout << parent[i] << endl;
    return 0;
}