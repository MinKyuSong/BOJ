#include <iostream>
#include <vector>

using namespace std;

int map[10][10];
bool visit[10];
int n;
int result = 10000001;

void solution(int node, int begin, int count, int dist)
{

    if (count == n - 1 && map[node][begin] > 0)
    {
        dist += map[node][begin];
        if (result > dist)
        {
            result = dist;
        }
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (visit[i] == false && map[node][i] > 0)
            {
                visit[i] = true;
                dist += map[node][i];
                solution(i, begin, count + 1, dist);
                dist -= map[node][i];
                visit[i] = false;
            }
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        visit[i] = true;
        solution(i, i, 0, 0);
        visit[i] = false;
    }
    cout << result << endl;
    return 0;
}