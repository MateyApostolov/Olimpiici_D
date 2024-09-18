#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, l, r;
    cin >> n >> q;
    long long pref[n + 1];
    int nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    pref[1] = nc[0];
    for(int i = 2; i <= n; i++) {
        pref[i] = pref[i - 1] + nc[i - 1];
    }
    for(int i = 0; i < q; i++) {
        long long k, kc, sum = 0;
        cin >> l >> r >> k;
        for(int i = 0; i < k; i++) {
            cin >> kc;
            sum += pow(nc[kc - 1], 2) - nc[kc - 1];
        }
        if(l == 1) {
            sum += pref[r];
        } else {
            sum += pref[r] - pref[l - 1];
        }
        cout << sum << '\n';
    }
    return 0;
}
