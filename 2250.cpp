#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int tree[100001][4];
int parent[100001];
int cnt = 1;
int depth = 0;
void inorder(int node, int lv)
{
    if (tree[node][0] != -1)
        inorder(tree[node][0], lv + 1);

    tree[node][2] = cnt++;
    tree[node][3] = lv;
    if (lv > depth)
        depth = lv;
    if (tree[node][1] != -1)
        inorder(tree[node][1], lv + 1);
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a][0] = b;
        tree[a][1] = c;
        if (b > 0)
            parent[b] = a;
        if (c > 0)
            parent[c] = a;
    }

    int root;
    for (int i = 1; i <= N; i++)
        if (parent[i] == 0)
        {
            root = i;
            break;
        }

    inorder(root, 1);
    vector<vector<int>> level(depth + 1);
    for (int i = 1; i <= N; i++)
        level[tree[i][3]].push_back(tree[i][2]);

    int anslv = 0, answidth = 0;
    for (int i = 1; i <= depth; i++)
    {
        int tmax = 0, tmin = 100002;
        for (int loc : level[i])
        {
            if (loc > tmax)
                tmax = loc;
            if (loc < tmin)
                tmin = loc;
        }
        if (tmax - tmin + 1 > answidth)
        {
            answidth = tmax - tmin + 1;
            anslv = i;
        }
    }
    cout << anslv << " " << answidth << endl;
    return 0;
}