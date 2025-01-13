#include <bits/stdc++.h>
using namespace std;

const int maxk = 51;
long long dp[maxk][maxk];
int k, n;

int main () {
    for(n = 1; n < maxk; n++) {
        for(k = 1; k < maxk; k++) {
            if(n == 1) dp[n][k] = k;
            else dp[n][k] = dp[n][k - 1] + dp[n - 1][k - 1];
        }
    }
    cin >> k >> n;
    cout << dp[n][k];
    return 0;
}
