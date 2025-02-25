#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) + 1;
int t[maxn], brd[maxn];
int main () {
    int n, m, ans = 0, mod = pow(10, 9) + 7, nc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        for(int x = m; x <= n; x += m) {
            if(__gcd(x, nc) == m) {
                ans += t[x];
                ans %= mod;
            }
            t[__gcd(x, nc)] += brd[x];
            t[__gcd(x, nc)] %= mod;
        }
        brd[nc]++;
    }
    cout << ans;
    return 0;
}
