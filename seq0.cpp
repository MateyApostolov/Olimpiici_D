#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    int dp[n + 1] = {};
    dp[0] = 1;
    for(int i = 1; i < k; i++) {
        dp[i] = dp[i - 1] * 2;
    }
    dp[k] = dp[k - 1] * 2 - 1;
    for(int i = k + 1; i <= n; i++) {
        dp[i] += dp[i - 1] * 2 - dp[i - k -  1];

    }
    cout << dp[n];

    return 0;
}
