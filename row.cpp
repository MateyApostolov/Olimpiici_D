#include <bits/stdc++.h>
using namespace std;

const int maxn = 300000;
int pref[5][maxn], h[5];

int main () {
    int n, a, b, z, q, x, y;
    cin >> n;
    for(int i1 = 0; i1 < n; i1++) {
        cin >> a >> b >> z;
        pref[z][0] = a * b;
        for(int i2 = 1; i2 < maxn; i2++) {
            pref[z][i2] = pref[z][i2 - 1] + a * b;
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> x >> y >> z;
        cout << pref[z][y] - pref[z][x] << '\n';
    }
    return 0;
}
