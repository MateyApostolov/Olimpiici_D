#include <bits/stdc++.h>
using namespace std;

int main () {
    int t, n, k;
    cin >> t;
    for(int i1 = 0; i1 < t; i1++) {
        cin >> n >> k;
        bool t = false;
        for(int i2 = (k * (k + 1)) / 2; i2 <= n; i2++) {
            if(n % i2 == 0) {
                cout << n / i2 << "\n";
                t = true;
                break;
            }
        }
            if(!t) cout << "-1\n";
    }
    return 0;
}

