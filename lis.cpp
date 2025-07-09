#include <bits/stdc++.h>
using namespace std;

const int maxn = 5001;
int dp[maxn];

int main () {
    int n, ans = 0;
    cin >> n;
    int nc[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
        for(int x = i - 1; x >= 1; x--) {
            if(nc[i] <= nc[x]) continue;
            if(dp[i] < dp[x]) {
                dp[i] = dp[x];
            }
        }
        dp[i]++;
    }
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}
