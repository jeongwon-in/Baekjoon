#define _CRT_SECURE_NO_WARNINGS
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (8)

int N, M;
int min = MAX_N * MAX_N;

char map[52][52];

int solve() {

	for (int i = 0; i <= N - 8; ++i) {
		for (int j = 0; j <= M - 8; ++j) {
			int cntB = 0;
			int cntW = 0;

			for (int k = 0; k < 8; ++k) {
				for (int l = 0; l < 8; ++l) {
					if ((k + l) % 2 == 0 && map[i + k][j + l] != 'W') {
						cntW++;
					}
					else if ((k + l) % 2 == 1 && map[i + k][j + l] != 'B') {
						cntW++;
					}

					if ((k + l) % 2 == 0 && map[i + k][j + l] != 'B') {
						cntB++;
					}
					else if ((k + l) % 2 == 1 && map[i + k][j + l] != 'W') {
						cntB++;
					}
				}
			}
			int total = 0;
			if (cntB < min || cntW < min) {
				total = cntB < cntW ? cntB : cntW;

				if (total < min) {
					min = total;
				}
			}
		}
	}
	return min;
}

void inputData(void) {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
	}
}


int main(void) {
	//(void)freopen("B1018.txt", "r", stdin);

	inputData();

	printf("%d", solve());

	return 0;
}