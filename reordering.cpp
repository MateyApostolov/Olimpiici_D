#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) + 1;
int nc[maxn], n;

bool ok (int num) {
    int bro = 0, maxc = nc[1];
    for(int i = 2; i <= n; i++) {
        if(maxc > nc[i]) bro++;
        maxc = max(maxc, nc[i]);
        ///cout << i << ' ' << bro << '\n';
        if(bro > num) return true;
    }
    return false;
}

int main () {
    int l = 0, r, mid;
    cin >> n;
    r = n;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
    }
    while(l <= r) {
        mid = (l + r) / 2;
        if(ok(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        ///cout << l << ' ';
    }
    cout << l;

    return 0;
}
