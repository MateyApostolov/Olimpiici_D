#include <bits/stdc++.h>
using namespace std;

const int maxn = 200;
int n, k1, k2;
int nc[maxn];
int memoiz[maxn][maxn][maxn];

int dp(int r1, int r2, int i) {
    if(i == n) return 0;
    if(memoiz[r1][r2][i] != -1) return memoiz[r1][r2][i];
    int v1 = 0, v2 = 0, v3 = dp(r1, r2, i + 1);
    if(r1 - nc[i] >= 0) v1 = nc[i] + dp(r1 - nc[i], r2, i + 1);
    if(r2 - nc[i] >= 0) v2 = nc[i] + dp(r1, r2 - nc[i], i + 1);
    return memoiz[r1][r2][i] = max(v1, max(v2, v3));
}

int main () {
    cin >> n >> k1 >> k2;
    for(int i1 = 0; i1 < maxn; i1++) {
        for(int i2 = 0; i2 < maxn; i2++) {
            for(int i3 = 0; i3 < maxn; i3++) {
                memoiz[i1][i2][i3] = -1;
            }
        }
    }
    for(int i = 0; i < n; i++) cin >> nc[i];
    cout << dp(k1, k2, 0);

    return 0;
}
