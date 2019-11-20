#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, M;
bool check[10];

void solution(int now, int idx, vector<int> &ans, const vector<int> &inputs)
{
    check[now] = true;
    ans[idx] = inputs[now];
    if (idx == M - 1)
    {
        for (int i = 0; i < M - 1; i++)
            cout << ans[i] << " ";
        cout << ans[M - 1] << '\n';
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            solution(i, idx + 1, ans, inputs);
        }
    }
    check[now]=false;

    return;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    vector<int> ans(M);
    vector<int>inputs(N);
    for(int i=0;i<N;i++)
    {
        cin>>inputs[i];
    }
    sort(inputs.begin(),inputs.end());
    for (int i = 0; i < N; i++)
    {
        solution(i, 0, ans, inputs);
    }

    return 0;
}