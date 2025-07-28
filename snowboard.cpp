#include <bits/stdc++.h>
using namespace std;

const int maxn = 202;
long long dp[maxn][maxn], h[maxn][maxn];

int main () {
    int n, m, p;
    cin >> n >> m >> p;
    long long d2_62 = 1;
    for(int i = 0; i < 62; i++) d2_62 *= 2;
    dp[1][1] = 1;
    for(int x = 1; x < n + m; x++) {
        for(int r = 1; r <= n; r++) {
            for(int c = 1; c <= m; c++) {
                h[r][c] = ((dp[r - 1][c] + dp[r][c - 1]) % d2_62 + dp[r - 1][c - 1]) % d2_62;
            }
        }
        for(int r = 1; r <= n; r++) {
            for(int c = 1; c <= m; c++) {
                dp[r][c] = h[r][c];
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
