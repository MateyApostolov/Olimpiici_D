#include <bits/stdc++.h>
using namespace std;

const int maxi = pow(10, 6);
int n, m, k, l, r, mid;
int nc[maxi], kl[maxi];

bool ok (int t) {
    bool po[maxi] = {};
    int idx = 0, brk[maxi] = {};
    for(int i = 0; i < n; i++) {
        if(abs(nc[i] - kl[idx]) <= t && brk[kl[idx]] < k) {
            brk[kl[idx]]++;
            po[nc[i]] = true;
        } else {
            if(idx == m - 1) break;
            idx++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(!po[nc[i]]) return true;
    }
    return false;
}


int main () {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        r = max(r, nc[i]);
    }
    for(int i = 0; i < m; i++) {
        cin >> kl[i];
        r = max(r, kl[i]);
    }
    sort(nc, nc + n);
    sort(kl, kl + m);
    while(l <= r) {
        mid = (l + r) / 2;
        if(ok(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}
