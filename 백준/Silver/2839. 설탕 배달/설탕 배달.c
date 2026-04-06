#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
int cnt = -1;

int Three[4] = { 3, 6, 9, 12 };
int solve(void) {

	if (N % 5 == 0) {
		cnt = N / 5;
	}
	else {
		for (int i = 0; i < 4; ++i) {
			int n = N - Three[i];
			if (n >= 0 && n % 5 == 0) {
				cnt = n / 5;
				cnt += i + 1;
			}
		}
	}
	return cnt;
}

int main(void) {

	scanf("%d", &N);

	printf("%d", solve());

	return 0;
}