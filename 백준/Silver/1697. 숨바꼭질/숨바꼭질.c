#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (100000 + 1)

int N, K;
int subin[MAX_N];

typedef struct _node {
	int X;
}node;

node Queue[MAX_N];
int front, rear;

int solve(void) {

	if (N == K) return 0;

	int nX, i;
	node curr;

	front = rear = 0;
	Queue[rear++] = (node){ N };
	subin[N] = 1;

	while (front != rear) {

		curr = Queue[front++];

		int dX[3] = { -1, 1, curr.X };
		for (i = 0; i < 3; ++i) {
			nX = curr.X + dX[i];

			if (nX < 0 || nX >= MAX_N) continue;

			if (subin[nX] == 0) {
				Queue[rear++] = (node){ nX };
				subin[nX] = subin[curr.X] + 1;

				if (nX == K) {
					return subin[K] - 1;
				}
			}
		}
	}
}

void inputData(void) {
	scanf("%d %d", &N, &K);
}

int main(void) {

	inputData();

	printf("%d", solve());

	return 0;
}