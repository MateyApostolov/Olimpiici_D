#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000001;
int brdel[maxn];

void eratosten (int n) {
    for(long long d = 1; d <= n; d++) {
        for(long long k = d; k <= n; k += d) {
            brdel[k]++;
        }
    }
    return;
}

int main () {
    int n, maxd = 0, hi;
    cin >> n;
    eratosten(n);
    for(int i = 1; i <= n; i++) {
        if(maxd < brdel[i]) {
            maxd = brdel[i];
            hi = i;
        }
    }
    cout << hi << '\n' << maxd;
    return 0;
}

