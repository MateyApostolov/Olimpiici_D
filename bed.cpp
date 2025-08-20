#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int nc[n + 1], dp[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
    }
    dp[1] = nc[1];
    dp[2] = max(nc[1], nc[2]);
    dp[3] = max(nc[1], max(nc[2], nc[3]));
    for(int i = 4; i <= n; i++) {
        int v1, v2, v3;
        v1 = nc[i] + dp[i - 1];
        v2 = max(nc[i - 1],nc[i]) + dp[i - 2];
        v3 = max(nc[i - 2], max(nc[i - 1], nc[i])) + dp[i - 3];
        dp[i] = min(v1, min(v2, v3));
    }
    cout << dp[n];
    return 0;
}
