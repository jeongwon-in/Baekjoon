#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N (100000 + 2)
#define MAX_X (100 + 2)

int T, n;
char p[MAX_N];
char arr[MAX_N * 10];
int N[MAX_N];

void inputData(void) {

	scanf("%s %d %s", p, &n, arr);

	char* ptr = strtok(arr, "[],");
	for (int i = 0; ptr != NULL; ++i) {
		N[i] = atoi(ptr);
		ptr = strtok(NULL, "[],");
	}
}


void solve(void) {
	int L = 0;
	int R = n - 1;
	int p_len = strlen(p);
	bool is_Reverse = 0;

	for (int i = 0; i < p_len; ++i) {

		if (p[i] == 'R') {
			is_Reverse = !is_Reverse;
		}
		else if (p[i] == 'D') {

			if (L > R) {
				printf("error\n");
				return;
			}

			if (!is_Reverse) {
				L++;
			}
			else {
				R--;
			}
		}
	}

	printf("[");

	if (is_Reverse) {
		for (int i = R; i >= L; --i) {
			printf("%d", N[i]);
			if (i > L) printf(",");
		}
	}
	else {
		for (int i = L; i <= R; ++i) {
			printf("%d", N[i]);
			if (i < R) printf(",");
		}
	}

	printf("]\n");

}


int main(void) {

	//(void)freopen("B5430.txt", "r", stdin);

	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		inputData();

		solve();
	}

	return 0;
}