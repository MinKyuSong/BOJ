#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n, m, r, c, d;
	int i, j;
	int iloc, jloc, dir, status, count = 0;
	int** map;
	int** cleanmap;

	//�������� �Է�
	scanf("%d %d", &n, &m);
	//���� �޸� �Ҵ�
	map = (int**)malloc(sizeof(int*)*n);
	cleanmap = (int**)malloc(sizeof(int*)*n);

	for (i = 0; i < n; i++) {
		map[i] = (int*)malloc(sizeof(int)*m);
		cleanmap[i]= (int*)malloc(sizeof(int)*m);
	}
	//�κ����� �Է�
	scanf("%d %d %d", &r, &c, &d);
	//���� �ʱ�ȭ
	for(i=0;i<n;i++)
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			cleanmap[i][j] = 1;
		}

	//�κ� �ൿ ���� �Է�
	while (1) {
		//1��: ���� ��ġ�� û���Ѵ�.
		cleanmap[r][c] = 0;
		count++;
		dir = d;
		status = 1;
		//2��: ���� ��ġ���� ���� ������ �������� ���ʹ������
		//     ���ʴ�� Ž���� �����Ѵ�.
		for (i = 0; i < 4; i++) {
			dir = (dir + 3) % 4;
			switch (dir)
			{
			//��
			case 0:
				iloc = r - 1;
				jloc = c;
				break;
			//��
			case 1:
				iloc = r;
				jloc = c + 1;
				break;
			//��
			case 2:
				iloc = r + 1;
				jloc = c;
				break;
			//��
			case 3:
				iloc = r;
				jloc = c - 1;
				break;

			default:
				break;
			}

			//2-1��:���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�,
			//�� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
			if (cleanmap[iloc][jloc] == 1&&map[iloc][jloc]==0) {
				d = dir;
				r = iloc;
				c = jloc;
				status = 0;
				break;
			}
			//2-2��:���� ���⿡ û���� ������ ���ٸ�,
			//�� �������� ȸ���ϰ� 2������ ���ư���.
			else {
				d = dir;
			}
		}
		if (i == 4 && status == 1) {
			switch (d)
			{
				//��
			case 0:
				iloc = r + 1;
				jloc = c;
				break;
				//��
			case 1:
				iloc = r;
				jloc = c - 1;
				break;
				//��
			case 2:
				iloc = r - 1;
				jloc = c;
				break;
				//��
			case 3:
				iloc = r;
				jloc = c + 1;
				break;

			default:
				break;
			}
			//2-3��:�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��,
			//�ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
			if (map[iloc][jloc] == 0) {
				r = iloc;
				c = jloc;
				count--;
				continue;
			}
			//2-4��:�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭,
			//���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
			else {
				break;
			}
		}
	}

	//��� ���
	printf("%d\n", count);

	//�޸� ��ȯ
	for (i = 0; i < n; i++) {
		free(map[i]);
		free(cleanmap[i]);
	}

	free(map);
	free(cleanmap);

	return 0;
}