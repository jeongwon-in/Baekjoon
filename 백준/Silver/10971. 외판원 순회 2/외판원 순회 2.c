#include <stdio.h>

#define MAX_N 11
#define INF 1e9  // 충분히 큰 값으로 설정

int N;
int map[MAX_N][MAX_N];
int visited[MAX_N];
int min_cost = INF;

// cur: 현재 도시, count: 방문한 도시 수, total_cost: 현재까지의 비용
void dfs(int cur, int count, int total_cost) {
    // 1. 가지치기 (현재 비용이 이미 최소 비용보다 크면 더 볼 필요 없음)
    if (total_cost >= min_cost) return;

    // 2. 모든 도시를 방문했을 때
    if (count == N) {
        // 마지막 도시에서 시작점(1번 도시)으로 돌아갈 수 있는지 확인
        if (map[cur][1] != 0) {
            int final_cost = total_cost + map[cur][1];
            if (final_cost < min_cost) {
                min_cost = final_cost;
            }
        }
        return;
    }

    // 3. 다음 도시 탐색
    for (int i = 1; i <= N; i++) {
        // 길이 있고, 아직 방문하지 않은 도시라면
        if (map[cur][i] != 0 && !visited[i]) {
            visited[i] = 1;
            dfs(i, count + 1, total_cost + map[cur][i]);
            visited[i] = 0; // 백트래킹 (복구)
        }
    }
}

int main() {
    // 입력 처리
    if (scanf("%d", &N) == 0) return 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // 1번 도시부터 시작
    visited[1] = 1;
    dfs(1, 1, 0);

    printf("%d\n", min_cost);

    return 0;
}