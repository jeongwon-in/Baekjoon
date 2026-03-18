#define _CRT_SECURE_NO_WARNINGS
#define SIZE(a) (sizeof(a))/sizeof((a)[0])

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (100+1)
int adjM[MAX_N][MAX_N]; // 인접 행렬
int adjL[MAX_N][MAX_N]; // 인접 리스트
int visited[MAX_N]; // 방문표시
int V, E;
int cnt; // 감염된 컴퓨터의 수

void inputDataM(void) {
    scanf("%d", &V);
    scanf("%d", &E);

    int from, to;

    for (int i = 0; i < E; ++i) {
        scanf("%d %d", &from, &to);

        adjM[from][to] = 1;
        adjM[to][from] = 1;
    }

}

void inputDataL(void) {
    scanf("%d", &V);
    scanf("%d", &E);

    int from, to;

    for (int i = 0; i < E; ++i) {
        scanf("%d %d", &from, &to);

        adjL[from][++adjL[from][0]] = to;
        adjL[to][++adjL[to][0]] = from;
    }

}

void print_adjM(void) {
    for (int i = 1; i <= V; ++i) {
        printf("%d : ", i);
        for (int j = 1; j <= V; ++j) {
            printf("%d ", adjM[i][j]);
        }
        printf("\n");
    }

}

void print_adjL(void) {
    for (int i = 1; i <= V; ++i) {
        printf("%d : ", i);
        for (int j = 0; j <= adjL[i][0]; ++j) {
            printf("%d ", adjL[i][j]);
        }
        printf("\n");
    }

}

// 인접행렬
// curr : 웜바이러스에 감염된 정점
void testadjM(int curr) {
    for (int i = 1; i <= V; ++i) {
        if ((adjM[curr][i] == 1) && (visited[i] == 0)) {
            ++cnt;
            visited[i] = 1;
            testadjM(i);
        }
    }

}

// 인접 리스트
// curr : 웜바이러스에 감염된 정점 번호
// adjL[curr][0] : 연결된 컴퓨터 개수 (i=1;i<=adjL[curr][0];++i)
void testadjL(int curr) {

    int next;

    for (int i = 1; i <= adjL[curr][0]; ++i) {
        next = adjL[curr][i];
        if (visited[next] == 0) {
            visited[next] = 1;
            cnt++;
            testadjL(next);
        }
    }

}


int main(void) {
    //(void)freopen("B2606.txt", "r", stdin);

    memset(adjM, 0, sizeof(adjM));
    memset(visited, 0, sizeof(visited));
    inputDataL();

    cnt = 0;
    visited[1] = 1;
    testadjL(1);
    printf("%d", cnt);


    return 0;
}