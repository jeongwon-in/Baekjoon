
#define _CRT_SECURE_NO_WARNINGS
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int X;
int Jimin = 64;
int cnt;

int solve(void) {

	while (X > 0) {
		while (Jimin > X) {
			Jimin /= 2;
		}
		X -= Jimin;
		cnt++;
	}
	return cnt;
}


int main(void) {
	scanf("%d", &X);

	printf("%d", solve());
	return 0;
}