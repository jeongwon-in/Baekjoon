int N;
int COL[15];
int UP[30];
int DOWN[30];
int total_count = 0;

void test(int N, int row) {

    if (row > N) {
        total_count++;
        return;
    }

    for (int col = 1; col <= N; ++col) {
        // 조건 : COL(세로) 겹치지 않고, DOWN(대각선)과 UP(대각선)도 겹치지 않을때 
        if ((COL[col] == 0) && (DOWN[row - col + N] == 0) && (UP[row + col] == 0)) {
            COL[col] = 1;
            DOWN[row - col + N] = 1;
            UP[row + col] = 1;

            test(N, row + 1);

            COL[col] = 0;
            DOWN[row - col + N] = 0;
            UP[row + col] = 0;
            continue;
        }
    }
}

int main(void) {

    scanf("%d", &N);
    test(N, 1);

    printf("%d", total_count);

    return 0;
}