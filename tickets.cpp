#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int dp[n + 1] = {}, t[n + 1], p[n];
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for(int i = 1; i < n; i++) {
        cin >> p[i];
    }
    dp[1] = t[1];
    dp[2] = min(t[1] + t[2], p[1]);
    for(int i = 3; i <= n; i++) {
        dp[i] = min(t[i] + dp[i - 1], p[i - 1] + dp[i - 2]);
    }
    cout << dp[n];
    return 0;
}
