#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<deque>
using namespace std;

int main(void)
{
	deque<int> wheel[5];

	// �Է�
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
		// ���� Ȯ��
		int i, j, dt;
		for (i = w - 1, j = w, dt = d; i > 0; i--, j--)
		{
			// �ڽ��� 2���� �������� 6�� Ȯ��
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
		// ���� ������
		for (i = 1; i < 5; i++)
		{
			int nTemp;
			// �ð�
			if (flag[i] == 1)
			{
				nTemp = wheel[i].back();
				wheel[i].push_front(nTemp);
				wheel[i].pop_back();
			}
			// �ݽð�
			else if (flag[i] == -1)
			{
				nTemp = wheel[i].front();
				wheel[i].push_back(nTemp);
				wheel[i].pop_front();
			}
		}

		for (i = 0; i < 5; i++)
			flag[i] = 0;
		// ������ Ȯ��
		for (i = w + 1, j = w, dt = d; i < 5; i++, j++)
		{
			// �ڽ��� 6���� ������ 2�� Ȯ��
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
		// ������ ������
		for (i = 1; i < 5; i++)
		{
			int nTemp;
			// �ð�
			if (flag[i] == 1)
			{
				nTemp = wheel[i].back();
				wheel[i].push_front(nTemp);
				wheel[i].pop_back();
			}
			// �ݽð�
			else if (flag[i] == -1)
			{
				nTemp = wheel[i].front();
				wheel[i].push_back(nTemp);
				wheel[i].pop_front();
			}
		}

		// �ڱ� �ڽ� ������
		{
			int nTemp;
			// �ð�
			if (d == 1)
			{
				nTemp = wheel[w].back();
				wheel[w].push_front(nTemp);
				wheel[w].pop_back();
			}
			// �ݽð�
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