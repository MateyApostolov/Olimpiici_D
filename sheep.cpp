#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 3);
long long nc[maxn];
long long n, k, l, r = INT_MAX, mid;

bool ok (long long t) {
    long long currt = 0, currk = 0, r = -1;
    bool vis[maxn] = {};
    for(int i = 1; i < n; i++) {
        if(vis[i]) continue;
        while(r + 1 < n) {
            r++;
            if(currt + nc[r] > t || vis[r]) continue;
            currt += nc[r];
            vis[r] = true;
        }
        r = i - 1;
        currk++;
        currt = 0;
    }
    if(currk > k) return true;
    return false;
}

int main () {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    sort(nc, nc + n);
    reverse(nc, nc + n);
    l = nc[0];
    while(l <= r) {
        mid = (l + r) / 2;
        if(ok(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        ///cout << l << '\n';
    }
    cout << l;

    return 0;
}
