#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void go(int n, const vector<char> &alpha, string password, int i);
bool check(string &password);

void go(int n, const vector<char> &alpha, string password, int i)
{
    if (password.length() == n)
    {
        if (check(password))
        {
            cout << password << '\n';
        }
        return;
    }
    if (i >= alpha.size())
        return;
    go(n, alpha, password + alpha[i], i + 1);
    go(n, alpha, password, i + 1);
    return;
}

bool check(string &password)
{
    int vowelCount = 0;
    int consonantCount = 0;
    string vowels = "aeiou";

    for (char &c : password)
    {
        if (find(vowels.begin(), vowels.end(), c) != vowels.end())
        {
            vowelCount++;
        }
        else
        {
            consonantCount++;
        }
    }
    return consonantCount >= 2 && vowelCount >= 1;
}

int main(void)
{
    int L, C;
    cin >> L >> C;
    vector<char> alpha(C);

    for (int i = 0; i < C; i++)
        cin >> alpha[i];
    sort(alpha.begin(), alpha.end());

    go(L, alpha, "", 0);
    return 0;
}