#include <iostream>
using namespace std;

#define MAX_N (1000000 + 2)

long long N, M, H;
long long Trees[MAX_N];

// 내림차순
int compare(const void* a, const void* b) {
	return (*(long long*)b > *(long long*)a) - (*(long long*)b < *(long long*)a);
}

long long solve(void) {

	long long L = 0;
	long long R = Trees[0];

	long long ret = -1;

	while (L <= R) {
		H = (L + R) / 2;
		long long sum = 0;

		for (int i = 0; i < N; ++i) {

			if (Trees[i] >= H) {
				sum += Trees[i] - H ;
			}
		}

		if (sum == M) {
			return H;
		}

		if (sum > M) {
			ret = H;
			L = H + 1;
		}
		else if(sum < M) {
			R = H - 1;
		}
	}
	return ret;
}

void inputData(void) {

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> Trees[i];
	}

	qsort(Trees, N, sizeof(long long), compare);
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	inputData();

	cout << solve() << endl;

}
