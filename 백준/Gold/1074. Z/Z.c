#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, r, c;
int cnt = 0;

void Z(int size) {

	if (size == 1) return;

	int A = size / 2;
	int S = A * A;

	if (r < A && c < A) {
		// 1분면
		Z(A);
	}
	else if (r < A && c >= A) {
		// 2분면
		cnt += S;
		c -= A;
		Z(A);

	}
	else if (r >= A && c < A) {
		// 3분면
		cnt += (2 * S);
		r -= A;
		Z(A);

	}
	else {
		// 4분면
		cnt += (3 * S);
		r -= A;
		c -= A;
		Z(A);
	}
}

void inputData(void) {
	scanf("%d %d %d", &N, &r, &c);
}

int main(void) {
	inputData();

	int A = 1 << N;

	Z(A);

	printf("%d", cnt);

	return 0;
}
