#include <bits/stdc++.h>
using namespace std;

const int maxn = 10e5 + 2;
int lr[maxn], rr[maxn], lc[maxn], rc[maxn], brc[maxn], brr[maxn], fr, fc;

int main () {
    int h, w, n;
    cin >> h >> w >> n;
    int r[n], c[n];
    for(int i = 0; i < n; i++) {
        cin >> r[i] >> c[i];
        int x = r[i], y = c[i];
        lr[x] = min(lr[x], y);
        rr[x] = max(rr[x], y);
        brr[x]++;
        lc[y] = min(lc[y], x);
        rc[y] = max(rc[y], x);
        brc[y]++;
    }
    for(int i = 0; i < n; i++) {
        int x = r[i], y = c[i];
        if(brr[x] != rr[x] - lr[x] + 1) fr++;
        if(brc[y] != rc[y] - lc[y] + 1) fc++;
    }
    if(fr == 0 && fc == 0) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
