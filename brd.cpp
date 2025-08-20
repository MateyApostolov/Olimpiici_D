#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, mc;
    cin >> n >> m;
    int dp[n + 2], ld[n + 1];
    bool wr[m + 1] = {};
    for(int i = 0; i < m; i++) {
        cin >> mc;
        wr[mc] = true;
    }
    dp[1] = 1;
    ld[1] = 0;

    dp[2] = 2;
    ld[2] = 1;
    if(wr[2]) {
        dp[2] = 2;
        ld[2] = 1;
    }
    dp[3] = 1;
    ld[3] = 0;
    if(wr[3]) {
        dp[3] = dp[2] + 1;
        ld[3] = 2;
    }
    dp[4] = 1;
    ld[4] = 0;
    if(wr[4]) {
        dp[4] = dp[3] + 1;
        ld[4] = 3;
    }
    for(int i = 5; i <= n + 1; i++) {
        dp[i] = dp[i - 1] + 1;
        ld[i] = i - 1;
        if(!wr[i]) {
            if(!wr[i - 1]) {
                dp[i] = dp[i - 2] + 1;
                ld[i]
            }
        }
    }
    return 0;
}
