#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool check[10];

void solution(int now, int idx, vector<int> &ans)
{
    check[now] = true;
    ans[idx] = now;
    if (idx == M - 1)
    {
        for (int i = 0; i < M - 1; i++)
            cout << ans[i] << " ";
        cout << ans[M - 1] << '\n';
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (!check[i])
                solution(i, idx + 1, ans);
        }
    }
    check[now] = false;

    return;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    vector<int> ans(M);
    for (int i = 1; i <= N; i++)
    {
        solution(i, 0, ans);
    }

    return 0;
}