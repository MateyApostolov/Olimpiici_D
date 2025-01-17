#include <bits/stdc++.h>
using namespace std;

int main () {
    int t, n, k, gaus;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> k;
        gaus = ((k + 1) * k) / 2;
        if(gaus > n) {
            cout << -1 << '\n';
            continue;
        }
        if(k == 1) {
            cout << n << '\n';
            continue;
        }
        for(int x = n / 2; x >= 1; x--) {
            if(n % x == 0 && n / x >= gaus) {
                cout << x << '\n';
                break;
            }
        }
    }

    return 0;
}
