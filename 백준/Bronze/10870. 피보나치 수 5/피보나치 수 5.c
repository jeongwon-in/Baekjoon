#define _CRT_SECURE_NO_WARNINGS
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int fibo(int L) {

	if (L == 0) {
		return 0;
	}
	if (L == 1) {
		return 1;
	}
	return fibo(L - 1) + fibo(L - 2);
}

int main(void) {

	int N;

	scanf("%d", &N);

	printf("%d", fibo(N));

	return 0;
}