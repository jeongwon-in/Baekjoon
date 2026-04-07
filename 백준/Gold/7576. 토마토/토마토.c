#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (1000 + 2)

int R, C;
int map[MAX_N][MAX_N];
int cnt = 0;

typedef struct _node {
	int r, c;
}node;

node Queue[MAX_N * MAX_N];
int front, rear;


int dR[4] = { -1, 1, 0, 0 };
int dC[4] = { 0, 0, 1, -1 };

int solve(void) {

	node curr;
	int nR, nC;
	int time = 0;

	while (front != rear) {
		curr = Queue[front++];
		time = map[curr.r][curr.c];

		for (int i = 0; i < 4; ++i) {
			nR = curr.r + dR[i];
			nC = curr.c + dC[i];

			if (nR < 0 || nR >= R || nC < 0 || nC >= C) continue;

			if (map[nR][nC] == 0) {
				Queue[rear++] = (node){ nR, nC };
				map[nR][nC] = time + 1;
				cnt--;
			}
		}
	}
	return time - 1;
}


void inputData(void) {

	scanf("%d %d", &C, &R);

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				Queue[rear++] = (node){ i, j };
			}
			else if(map[i][j] == 0) {
				cnt++;
			}
		}
	}

}

int main(void) {

	inputData();

	if (cnt == 0) {
		printf("0");
		return 0;
	}

	int result = solve();

	if (cnt > 0) {
		printf("-1");
		return 0;
	}

	printf("%d", result);

	return 0;
}