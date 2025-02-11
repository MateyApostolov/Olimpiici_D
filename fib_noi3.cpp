#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, pr = 1, ppr = 1, nc;
    cin >> n >> m;
    if(n < 3) {
        cout << 1;
        return 0;
    }
    for(int i = 2; i < n; i++) {
        nc = (pr + ppr) % m;
        ppr = pr;
        pr = nc;
    }
    cout << nc;
    return 0;
}
