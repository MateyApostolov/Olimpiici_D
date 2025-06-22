#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, a, b, c, ans = 0;
    cin >> n >> a >> b;
    bool dp[b + 1] = {};
    dp[0] = true;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        for(int x = b; x >= 0; x--) {
            if(dp[x] && x + c <= b) dp[x + c] = true;
        }
    }
    for(int i = a; i <= b; i++) ans += dp[i];
    cout << ans;
    return 0;
}
