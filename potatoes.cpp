#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    long long d2[n + 1][m + 1], dp[n + 1][m + 1];
    for(int r = 0; r <= n; r++) {
        for(int c = 0; c <= m; c++) {
            if(r == 0 || c == 0) dp[r][c] = 0;
            else {
                cin >> d2[r][c];
                dp[r][c] = d2[r][c];
            }
        }
    }
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            dp[r][c] += max(dp[r][c - 1], dp[r - 1][c]);
        }
    }
    cout << dp[n][m];
    return 0;
}
