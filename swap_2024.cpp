#include <bits/stdc++.h>
using namespace std;

const int maxn = 102;
const int maxs = 1e5;

long long dp[maxn][maxs][2], nc[maxn];

int main () {
    long long n, s, k, ansp, sum;
    cin >> n >> s >> k;
    ansp = k + s * (s + 1) / 2;
    for(int i = 1; i <= n; i++) cin >> nc[i];

    bool t = true;
    sum = nc[1];
    for(int i = 2; i <= n; i++) {
        if(i <= s) sum += nc[i];
        if(nc[i] > nc[i + 1]) {
            t = false;
            break;
        }
    }
    if(t) {
        cout << sum;
        return 0;
    }


    for(int i = 1; i <= s; i++) {
        for(int x = 0; x <= ansp; x++) {
            dp[i][x][0] = INT_MIN;
        }
    }
    for(int pos = 1; pos <= n; pos++) {
        for(int i = 0; i <= s; i++) {
            for(int ts = 0; ts <= ansp; ts++) {
                dp[i][ts][pos % 2] = dp[i][ts][1 - pos % 2];
                if(i > 0 && ts >= pos) dp[i][ts][pos % 2] = max(dp[i][ts][pos % 2], nc[pos] + dp[i - 1][ts - pos][1 - pos % 2]);
            }
        }
    }
    cout << dp[s][ansp][n % 2];
    return 0;
}
