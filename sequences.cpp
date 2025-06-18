#include <bits/stdc++.h>
using namespace std;

const int maxc = 31;
long long dp[maxc][maxc][maxc];

int main () {
    long long n, m, k, ans = 0;
    cin >> n >> m >> k;
    dp[0][0][0] = 1;
    for(int len = 0; len <= n; len++) {
        for(int las = 0; las <= m; las++) {
            for(int kr = 0; kr <= k; kr++) {
                for(int x = las + 1; x <= m; x++) {
                    dp[len + 1][x][1] += dp[len][las][kr];
                }
                if(len != 0 && las != 0) dp[len + 1][las][kr + 1] += dp[len][las][kr];
            }
        }
    }
    for(int las = 1; las <= m; las++) {
        for(int kr = 1; kr <= k; kr++) {
            ans += dp[n][las][kr];
        }
    }
    cout << ans;
    return 0;
}
