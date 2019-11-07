#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	queue<int> qnJosephus;
	for (int i = 1; i <= N; i++)
	{
		qnJosephus.push(i);
	}

	cout << "<";
	while (qnJosephus.size() > 1)
	{
		for (int i = 1; i < K; i++)
		{
			qnJosephus.push(qnJosephus.front());
			qnJosephus.pop();
		}
		cout << qnJosephus.front() << ", ";
		qnJosephus.pop();
	}
	cout << qnJosephus.front() << ">" << endl;
	return 0;
}