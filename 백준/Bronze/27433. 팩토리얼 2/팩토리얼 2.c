#define _CRT_SECURE_NO_WARNINGS
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long facto(int L) {

	if (L <= 0) {
		return 1;
	}

	return (long long)L * facto(L - 1);
}

int main(void) {

	int N;

	scanf("%d", &N);

	printf("%lld", facto(N));

	return 0;
}