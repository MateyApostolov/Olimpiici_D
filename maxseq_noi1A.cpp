#include <bits/stdc++.h>
using namespace std;

const int maxn = 5 * pow(10, 5);
int dp[maxn][2];

int main () {
    int n, nc, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        dp[nc][0] = dp[nc - 1][0] + 1;
        dp[nc][1] = max(dp[nc - 2][0] + 2, dp[nc - 1][1] + 1);
        ans = max(ans, max(dp[nc][0] + 1, dp[nc][1]));
    }
    cout << ans;
    return 0;
}
