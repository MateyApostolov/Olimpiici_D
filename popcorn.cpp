#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5);
int n, k, s, l, r = pow(10, 9), mid;
int nc[maxn];

bool ok (int num) {
    int idx = 1, hs = s * num;
    for(int i = 0; i < n; i++) {
        if(hs >= nc[i]) {
            hs -= nc[i];
        } else {
            if(hs == s * num) return true;
            idx++;
            hs = s * num;
            i--;
        }
    }
    if(idx <= k) return false;
    return true;
}

int main () {
    cin >> n >> k >> s;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    while(l <= r) {
        mid = (l + r) / 2;
        if(ok(mid)) {
            l = mid + 1;
        } else {
            r  = mid - 1;
        }
    }
    cout << l;

    return 0;
}
