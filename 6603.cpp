#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true)
    {
        int k;
        cin >> k;
        if (k == 0)
            break;

        vector<int> numSet(k);
        for (int i = 0; i < k; i++)
        {
            cin >> numSet[i];
        }

        sort(numSet.begin(), numSet.end());
        vector<int> combination;
        for (int i = 0; i < 6; i++)
        {
            combination.push_back(0);
        }
        for (int i = 0; i < k - 6; i++)
        {
            combination.push_back(1);
        }
        sort(combination.begin(), combination.end());
        do
        {
            for (int i = 0; i < numSet.size(); i++)
            {
                if (combination[i] == 0)
                    cout << numSet[i] << " ";
            }
            cout << "\n";
        } while (next_permutation(combination.begin(), combination.end()));

        cout << "\n";
    }
    return 0;
}