#define _CRT_SECURE_NO_WARNINGS
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%.12f", (double)a / b);

	return 0;
}
