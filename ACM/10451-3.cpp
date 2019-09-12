#include<iostream>
#include<vector>
using namespace std;

int group[1001];
int connection[1001];
void DFS(int v, const int count)
{
	group[v] = count;
	if (group[connection[v]] == 0)
		DFS(connection[v], count);
}
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)
			group[i] = 0;

		for (int i = 1; i <= N; i++)
			cin >> connection[i];

		int count = 0;
		for (int i = 1; i <= N; i++)
		{
			if (group[i] == 0)
			{
				count++;
				DFS(i, count);
			}
		}
		cout << count << endl;
	}
	return 0;
}