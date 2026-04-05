#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_K (10000 + 2)

int N, K;
long long K_len[MAX_K];

long long BinarySearch()
{
	long long L = 1;
	long long R = K_len[K - 1];
	long long M;
	long long ret = -1;

	while (L <= R)
	{
		M = (L + R) / 2;

		long long cnt = 0;
		for (int i = 0; i < K; ++i) {
			cnt += K_len[i] / M;
		}

		if (cnt >= N)
		{
			ret = M;
			L = M + 1;
		}
		else
		{
			R = M - 1;
		}
	}
	return ret;
}

int compare(const void* a, const void* b) {
	long long n1 = *(const long long*)a;
	long long n2 = *(const long long*)b;

	return (n1 > n2) - (n1 < n2);
}

void inputData(void) {
	scanf("%d %d", &K, &N);

	for (int i = 0; i < K; ++i) {
		scanf("%lld", &K_len[i]);
	}
}

int main(void) {
	inputData();

	qsort(K_len, K, sizeof(long long), compare);

	long long result = BinarySearch();

	printf("%lld", result);

	return 0;
}
