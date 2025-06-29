#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) + 1;
long long n, k, nc[maxn], l, r, mid;

bool ok (long long x) {
    long long s = nc[0];
    for(int i = 1; i < n; i++) {
        s += x;
        s = max(s, nc[i]);
        if(s > k) return false;
    }
    return true;
}

int main () {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    sort(nc, nc + n);
    r = nc[0];
    while(l <= r) {
        mid = (l + r) / 2;
        if(ok(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r;
    return 0;
}
