#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5);
int dp[maxn][2];

int main () {
    int n, nc;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> nc;
        dp[i][1] = dp[i - 1][0] + 3 * nc;
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + 2 * nc;
    }
    cout << max(dp[n][0], dp[n][1]);
    return 0;
}
