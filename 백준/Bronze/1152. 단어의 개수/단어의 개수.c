#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR (1000000 + 2)

char str[MAX_STR];
int cnt = 0;

void solve(void) {
	char* ptr = strtok(str, " \n\t");
	while (ptr != NULL) {
		cnt++;
		//printf("%s\n", ptr);
		ptr = strtok(NULL, " \n\t");
	}
}


int main(void) {

	fgets(str, sizeof(str), stdin);

	solve();

	printf("%d", cnt);

	return 0;
}