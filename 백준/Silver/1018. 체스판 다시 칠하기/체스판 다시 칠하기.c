#include <stdio.h>

#define MAX_N (8)

int N, M;
int min = MAX_N * MAX_N;

char map[52][52];

int solve() {

	// 8 * 8이 가능한 시작점
	for (int i = 0; i <= N - MAX_N; ++i) {
		for (int j = 0; j <= M - MAX_N; ++j) {
			int cntB = 0; // 시작점이 B라고 할때의 카운트

			for (int k = 0; k < MAX_N; ++k) {
				for (int l = 0; l < MAX_N; ++l) {
					// B일때
					if ((k + l) % 2 == 0 && map[i + k][j + l] != 'B') {
						cntB++;
					}
					else if ((k + l) % 2 == 1 && map[i + k][j + l] != 'W') {
						cntB++;
					}
				}
			}
			int cntW = MAX_N * MAX_N - cntB;
			int curr_min = cntB < cntW ? cntB : cntW;
			if (curr_min < min) min = curr_min;

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