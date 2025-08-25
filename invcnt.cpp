#include <bits/stdc++.h>
using namespace std;

const int maxn = 10e6 + 1;
int n, nc[maxn], h[maxn];
long long br_inv;

void inv_merge (int l, int r) {
    if(l == r) return;
    int mid = l + (r - l) / 2;
    inv_merge(l, mid);
    inv_merge(mid + 1, r);
    int L = l, R = mid + 1, idx = l;
    while(L <= mid || R <= r) {
        if(L > mid) h[idx++] = nc[R++];
        else if(R > r) h[idx++] = nc[L++];
        else if(nc[L] < nc[R]) h[idx++] = nc[L++];
        else {
            h[idx++] = nc[R++];
            br_inv += mid - L + 1;
        }
    }
    for(int i = l; i <= r; ++i) nc[i] = h[i];
}

int main () {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
    }
    inv_merge(1, n);
    cout << br_inv;
    return 0;
}
