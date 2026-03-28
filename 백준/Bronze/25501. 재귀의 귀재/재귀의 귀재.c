#include <stdio.h>
#include <string.h>

int cnt = 0;
int recursion(const char* s, int l, int r) {
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}

int N;
char str[1001][1001];

void inputData() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%s", str[i]);
	}
}

int main() {

	inputData();

	for (int i = 0; i < N; ++i) {
		int result = isPalindrome(str[i]);
		printf("%d %d\n", result, cnt);
		cnt = 0;
	}
}
