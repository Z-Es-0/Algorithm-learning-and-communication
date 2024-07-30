

int dp[N][N],qz[N][N];

void build(int rows, int cols) {
    memset(qz, 0, sizeof(int) * M * M);
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            qz[i][j] = dp[i][j]
                       + qz[i-1][j]
                       + qz[i][j-1]
                       - qz[i-1][j-1];
        }
    }
}

int finds(int r1, int c1, int r2, int c2) {
    return qz[r2][c2]
           - (r1 > 1 ? qz[r1-1][c2] : 0)
           - (c1 > 1 ? qz[r2][c1-1] : 0)
           + (r1 > 1 && c1 > 1 ? qz[r1-1][c1-1] : 0);
}