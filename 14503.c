#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n, m, r, c, d;
	int i, j;
	int iloc, jloc, dir, status, count = 0;
	int** map;
	int** cleanmap;

	//지도정보 입력
	scanf("%d %d", &n, &m);
	//지도 메모리 할당
	map = (int**)malloc(sizeof(int*)*n);
	cleanmap = (int**)malloc(sizeof(int*)*n);

	for (i = 0; i < n; i++) {
		map[i] = (int*)malloc(sizeof(int)*m);
		cleanmap[i]= (int*)malloc(sizeof(int)*m);
	}
	//로봇설정 입력
	scanf("%d %d %d", &r, &c, &d);
	//지도 초기화
	for(i=0;i<n;i++)
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			cleanmap[i][j] = 1;
		}

	//로봇 행동 로직 입력
	while (1) {
		//1번: 현재 위치를 청소한다.
		cleanmap[r][c] = 0;
		count++;
		dir = d;
		status = 1;
		//2번: 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터
		//     차례대로 탐색을 진행한다.
		for (i = 0; i < 4; i++) {
			dir = (dir + 3) % 4;
			switch (dir)
			{
			//북
			case 0:
				iloc = r - 1;
				jloc = c;
				break;
			//동
			case 1:
				iloc = r;
				jloc = c + 1;
				break;
			//남
			case 2:
				iloc = r + 1;
				jloc = c;
				break;
			//서
			case 3:
				iloc = r;
				jloc = c - 1;
				break;

			default:
				break;
			}

			//2-1번:왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면,
			//그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
			if (cleanmap[iloc][jloc] == 1&&map[iloc][jloc]==0) {
				d = dir;
				r = iloc;
				c = jloc;
				status = 0;
				break;
			}
			//2-2번:왼쪽 방향에 청소할 공간이 없다면,
			//그 방향으로 회전하고 2번으로 돌아간다.
			else {
				d = dir;
			}
		}
		if (i == 4 && status == 1) {
			switch (d)
			{
				//북
			case 0:
				iloc = r + 1;
				jloc = c;
				break;
				//동
			case 1:
				iloc = r;
				jloc = c - 1;
				break;
				//남
			case 2:
				iloc = r - 1;
				jloc = c;
				break;
				//서
			case 3:
				iloc = r;
				jloc = c + 1;
				break;

			default:
				break;
			}
			//2-3번:네 방향 모두 청소가 이미 되어있거나 벽인 경우에는,
			//바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
			if (map[iloc][jloc] == 0) {
				r = iloc;
				c = jloc;
				count--;
				continue;
			}
			//2-4번:네 방향 모두 청소가 이미 되어있거나 벽이면서,
			//뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
			else {
				break;
			}
		}
	}

	//결과 출력
	printf("%d\n", count);

	//메모리 반환
	for (i = 0; i < n; i++) {
		free(map[i]);
		free(cleanmap[i]);
	}

	free(map);
	free(cleanmap);

	return 0;
}