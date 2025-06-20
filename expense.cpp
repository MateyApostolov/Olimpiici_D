#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long nc[n], pref[n + 1] = {}, dp[n + 1] = {}, saved = 0;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    sort(nc, nc + n);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + nc[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if(i >= a) {
            saved = pref[i - a + b] - pref[i - a];
            dp[i] = max(dp[i], dp[i - a] + saved);
        }
        if(i >= c) {
            saved = pref[i - c + d] - pref[i - c];
            dp[i] = max(dp[i], dp[i - c] + saved);
        }
    }
    cout << pref[n] - dp[n];




    return 0;
}
