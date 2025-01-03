#include <bits/stdc++.h>
using namespace std;

const int d7 = pow(10, 9) + 7, d9 = pow(10, 9) + 9;

int main () {
    long long n, q, ql, qr, d = 0, k = 0, sum7 = 0, sum9 = 0;
    cin >> n >> q;
    long long a[n], l[q], idx[n];
    pair<long long, long long> r[q];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> ql >> qr;
        l[i] = ql - 1;
        r[i] = {qr - 1, ql - 1};
    }
    sort(l, l + q);
    sort(r, r + q);
    int hi = 0, he = 0;
    for(int i = 0; i < n; i++) {
        while(hi < q && i == l[hi]) {
            k++;
            hi++;
        }
        d += k;
        idx[i] = d;
        while(he < q && i == r[he].first) {
            k--;
            d = d - (r[he].first - r[he].second + 1);
            he++;
        }
    }
    for(int i = 0; i < n; i++) {
        sum7 = (sum7 + (idx[i] * a[i]) % d7) % d7;
        sum9 = (sum9 + (idx[i] * a[i]) % d9) % d9;
    }
    cout << sum7 << ' ' << sum9;
    return 0;
}
