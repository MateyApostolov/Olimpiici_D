#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    int t[n + 2][m + 2], dp[n + 2][m + 2], ans = INT_MAX;
    for(int r = 0; r <= n + 1; r++) {
        for(int c = 0; c <= m + 1; c++) {
            if(r == 0 || r == n + 1 || c == 0 || c == m + 1) dp[r][c] = INT_MAX;
            else {
                cin >> t[r][c];
                dp[r][c] = 0;
            }
        }
    }
    for(int c = 1; c <= m; c++) {
        for(int r = 1; r <= n; r++) {
            if(c == 1) dp[r][c] = t[r][c];
            else dp[r][c] = min(dp[r - 1][c - 1], min(dp[r][c - 1], dp[r + 1][c - 1])) + t[r][c];
        }
    }
    for(int r = 1; r <= n; r++) {
        ans = min(ans, dp[r][m]);
    }
    cout << ans;
    return 0;
}
