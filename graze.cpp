#include <bits/stdc++.h>
using namespace std;

const int maxi = pow(10, 6);
int n, m, k, l, r = pow(10, 8), mid;
int nc[maxi], kl[maxi];

bool ok (int t) {
    bool po[n] = {};
    int idx = 0, brk[m] = {};
    for(int i = 0; i < n; ) {
        if(abs(nc[i] - kl[idx]) <= t && brk[idx] < k) {
            brk[idx]++;
            po[i] = true;
            i++;
        } else {
            if(idx == m - 1) break;
            idx++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(!po[i]) return true;
    }
    return false;
}


int main () {
    bool t = false;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> nc[i];
    for(int i = 0; i < m; i++) cin >> kl[i];
    sort(nc, nc + n);
    sort(kl, kl + m);
    while(l <= r) {
        mid = (l + r) / 2;
        if(ok(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
            t = true;
        }
    }
    if(!t) cout << '-1';
    else cout << l;
    return 0;
}
