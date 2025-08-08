#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int nc[maxn], n, q, qc;

int bin (int num) {
    int l = 0, r = n - 1, m, ans = n;
    while(l <= r) {
        m = (l + r) / 2;
        if(nc[m] > num) {
            r = m - 1;
            ///ans = m;
        }else l = m + 1;
    }
    return l; /// l == ans && r == ans - 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> nc[i];
    sort(nc, nc + n);
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> qc;
        cout << bin(qc) << ' ';
    }

    return 0;
}
