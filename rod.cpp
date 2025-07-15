#include <bits/stdc++.h>
using namespace std;

const int maxn = 501;
int nc[maxn], pref[maxn], dp[maxn][maxn];

int rod (int l, int r) {
    if(l == r) return 0;
    if(dp[l][r] != 0) return dp[l][r];
    dp[l][r] = INT_MAX;
    for(int i = l; i < r; i++) {
        dp[l][r] = min(dp[l][r], rod(l, i) + rod(i + 1, r) + pref[r] - pref[l - 1]);
    }
    return dp[l][r];
}

int main () {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
        pref[i] = pref[i - 1] + nc[i];
    }
    cout << rod(1, n);


    return 0;
}
