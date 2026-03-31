#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long A, B, C;

long long solve(long long k) {

	if (k == 0)return 1;
	else if (k == 1) return A % C;

	long long solveHalf = solve(k / 2);
	
	long long result = (solveHalf * solveHalf) % C;



	if (k % 2 == 1) {
		result = (result * (A % C)) % C;
	}

	return result;
}

void inputData(void) {

	scanf("%lld %lld %lld", &A, &B, &C);
}

int main(void) {
	inputData();

	printf("%lld", solve(B));


	return 0;
}