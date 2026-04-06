#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (100 + 2)

int N, M;
int arr_N[MAX_N];
int sum = 0;
int max;

void solve(void) {

	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j < N - 1; ++j) {
			for (int k = j + 1; k < N; ++k) {

				sum = arr_N[i] + arr_N[j] + arr_N[k];

				if (max < sum && sum <= M) {
					max = sum;
				}

			}
		}
	}

}

int compare(const int* a, const int* b) {
	return (*a > *b) - (*a < *b);
}


void inputData(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr_N[i]);
	}

	qsort(arr_N, N, sizeof(int), compare);
}

int main(void) {

	inputData();

	solve();

	printf("%d", max);

	return 0;
}