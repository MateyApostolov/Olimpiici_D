#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, nc, q, x, y;
    cin >> n;
    long long pref[n];
    cin >> nc;
    pref[0] = nc;
    for(int i = 1; i < n; i++) {
        cin >> nc;
        pref[i] = pref[i - 1] + nc;
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> x >> y;
        if(x == 1) {
            cout << pref[y - 1] << "\n";
        } else {
            cout << pref[y - 1] - pref[x - 2] << "\n";
        }
    }

    return 0;
}
