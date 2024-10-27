#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) * 2 + 1, d7 = pow(10, 9) + 7, d9 = pow(10, 9) + 9;
int pref[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, q, nc, l, r, iz7 = 0, iz9 = 0;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> nc;
        pref[i] = pref[i - 1] + nc;
    }
    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        int h = 0;
        for(int x = l; x <= r; x++) {
            h += pref[r] - pref[x - 1];
        }
        iz7 = (iz7 + h) % d7;
        iz9 = (iz9 + h) % d9;
    }
    cout << iz7 % d7 << ' ' << iz9 % d9;
    return 0;
}
