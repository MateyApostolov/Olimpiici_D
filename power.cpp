#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) * 2 + 1, d7 = pow(10, 9) + 7, d9 = pow(10, 9) + 9;
long long pref[maxn], d[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, q, nc, l, r, iz7 = 0, iz9 = 0;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> nc;
        d[i] = nc * i;
        pref[i] = pref[i - 1] + nc;
    }
    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        int h7 = (d[r] - d[l]) % d7 - (l - 1) * (pref[r] - pref[l - 1]);
        int h9 = (d[r] - d[l]) % d9 - (l - 1) * (pref[r] - pref[l - 1]);
        iz7 = (iz7 + h7) % d7;
        iz9 = (iz9 + h9) % d9;
    }
    cout << iz7 % d7 << ' ' << iz9 % d9;
    return 0;
}
