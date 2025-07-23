#include <bits/stdc++.h>
using namespace std;

const int maxn = 202;
long long dp[maxn][maxn][maxn + maxn];

int main () {
    int n, m, p;
    cin >> n >> m >> p;
    long long d2_62 = 1;
    for(int i = 0; i < 62; i++) d2_62 *= 2;
    dp[1][1][0] = 1;
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            for(int h = 1; h < p; h++) {
                dp[r][c][h] = ((dp[r - 1][c][h - 1] + dp[r][c - 1][h - 1]) % d2_62 + dp[r - 1][c - 1][h - 1]) % d2_62;
            }
        }
    }
    cout << dp[n][m][p - 1];
    return 0;
}
