#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (100 + 2)

int T;
long long P[MAX_N] = { 1, 1, 1, 2, 2 };
int N[MAX_N];

void lookup() {

	for (int i = 5; i < MAX_N; ++i) {
		P[i] = P[i - 5] + P[i - 1];
	}
}

void inputData(void) {

	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &N[i]);
	}
	
}

void solve(void) {
	for (int i = 0; i < T; ++i) {
		printf("%lld\n", P[N[i] - 1]);
	}
}

int main(void) {

	inputData();

	lookup();

	solve();

	return 0;
}
