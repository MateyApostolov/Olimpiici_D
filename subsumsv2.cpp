#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 6) + 1;
bool dp[2 * maxc];

int main () {
    int n, c, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        dp[c + maxc] = true;
        if(c > 0) {
            for(int x = maxc - 1; x > 0; x--) {
                if(dp[x + maxc] && x + c < 2 * maxc) dp[x + c + maxc] = true;
            }
        } else {
            for(int x = 1; x < maxc; x++) {
                if(dp[x + maxc] && x + c < 2 * maxc) dp[x + c + maxc] = true;
            }
        }
    }
    for(int i = 0; i < 2 * maxc; i++) ans += dp[i];
    cout << ans;
    return 0;
}

