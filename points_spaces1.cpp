#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) + 1;
int k[maxn];
int pref[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, l, r;
    cin >> n;
    int nc[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
        k[nc[i]]++;
    }
    sort(nc, nc + n);
    for(int i = 1; i <= maxn; i++) {
        pref[i] = pref[i - 1] + k[i];

    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }

    return 0;
}
