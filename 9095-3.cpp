#include <iostream>
using namespace std;

int arr[12];
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i < 12; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        cout << arr[t] << "\n";
    }
    return 0;
}