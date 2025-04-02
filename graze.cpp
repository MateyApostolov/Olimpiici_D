#include <bits/stdc++.h>
using namespace std;

const int maxi = pow(10, 6);
int brk[maxi];

int main () {
    int n, m, k, idx = 0, hi = 0, maxr = 0;
    cin >> n >> m >> k;
    int nc[n], kl[m];
    for(int i = 0; i < n; i++) cin >> nc[i];
    for(int i = 0; i < m; i++) cin >> kl[i];
    sort(nc, nc + n);
    sort(kl, kl + m);
    while(hi < n) {
        while(brk[kl[idx + 1]] != 0 && idx + 1 < m && abs(nc[hi] - kl[idx]) > abs(nc[hi] - kl[idx + 1]) && brk[kl[idx + 1]] < k) {
            idx++;
        }
        brk[kl[idx]]++;
        maxr = max(maxr, abs(nc[hi] - kl[idx]));
        hi++;
        if(brk[kl[idx]] == k) idx = 0;
    }
    cout << maxr;
    return 0;
}
