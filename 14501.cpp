#include <iostream>

using namespace std;

int result = 0;
int n;
int profits[2][16];

void go(int day, int sum)
{
    if (day >= n)
        return;
    if (day + 1 <= n)
    {
        go(day + 1, sum);
    }
    if (day + profits[0][day] <= n)
    {
        go(day + profits[0][day], sum + profits[1][day]);
        if (sum + profits[1][day] > result)
        {
            result = sum + profits[1][day];
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
        cin >> profits[0][i] >> profits[1][i];
    }

    go(0, 0);

    cout << result << endl;
    return 0;
}