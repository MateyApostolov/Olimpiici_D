#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int mm[maxn][maxn];
int n, i, j;

int dp (int p, int d) {
    if(p == d) return 1;
    ///if(p > d) swap(p, d);
    if(mm[p][d] != 0) return mm[p][d];
    int v = 0;
    for(int x = p + 1; x <= d; x++) {
        v += dp(p, x);
        v += dp(x, d);
    }
    for(int x = p + 1; x <= n; x++) {
        v += dp(p, x);
        v += dp(x, d);
    }
    return mm[p][d] = v;
}


int main () {
    cin >> n >> i >> j;
    cout << dp(i, j);

    return 0;
}
