#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<deque>
using namespace std;

int main(void)
{
	deque<int> wheel[5];

	// 입력
	for (int i = 1; i < 5; i++)
		for (int j = 0; j < 8; j++)
		{
			int nTemp;
			scanf("%1d", &nTemp);
			wheel[i].push_back(nTemp);
		}

	int K;
	scanf("%d", &K);
	while (K--)
	{
		int w, d;
		scanf("%d %d", &w, &d);

		int flag[5];

		for (int i = 0; i < 5; i++)
			flag[i] = 0;
		// 왼쪽 확인
		int i, j, dt;
		for (i = w - 1, j = w, dt = d; i > 0; i--, j--)
		{
			// 자신의 2번과 오른쪽의 6번 확인
			if (wheel[i][2] == wheel[j][6])
			{
				dt = 0;
			}
			else
			{
				dt *= -1;
				flag[i] = dt;
			}
		}
		// 왼쪽 돌리기
		for (i = 1; i < 5; i++)
		{
			int nTemp;
			// 시계
			if (flag[i] == 1)
			{
				nTemp = wheel[i].back();
				wheel[i].push_front(nTemp);
				wheel[i].pop_back();
			}
			// 반시계
			else if (flag[i] == -1)
			{
				nTemp = wheel[i].front();
				wheel[i].push_back(nTemp);
				wheel[i].pop_front();
			}
		}

		for (i = 0; i < 5; i++)
			flag[i] = 0;
		// 오른쪽 확인
		for (i = w + 1, j = w, dt = d; i < 5; i++, j++)
		{
			// 자신의 6번과 왼쪽의 2번 확인
			if (wheel[i][6] == wheel[j][2])
			{
				dt = 0;
			}
			else
			{
				dt *= -1;
				flag[i] = dt;
			}
		}
		// 오른쪽 돌리기
		for (i = 1; i < 5; i++)
		{
			int nTemp;
			// 시계
			if (flag[i] == 1)
			{
				nTemp = wheel[i].back();
				wheel[i].push_front(nTemp);
				wheel[i].pop_back();
			}
			// 반시계
			else if (flag[i] == -1)
			{
				nTemp = wheel[i].front();
				wheel[i].push_back(nTemp);
				wheel[i].pop_front();
			}
		}

		// 자기 자신 돌리기
		{
			int nTemp;
			// 시계
			if (d == 1)
			{
				nTemp = wheel[w].back();
				wheel[w].push_front(nTemp);
				wheel[w].pop_back();
			}
			// 반시계
			else if (d == -1)
			{
				nTemp = wheel[w].front();
				wheel[w].push_back(nTemp);
				wheel[w].pop_front();
			}
		}
	}

	int nResult = 0;
	nResult += wheel[1].front();
	nResult += (wheel[2].front() * 2);
	nResult += (wheel[3].front() * 4);
	nResult += (wheel[4].front() * 8);
	printf("%d\n", nResult);

	return 0;
}