#include <bits/stdc++.h>
using namespace std;

int main () {
    long long a, b, n, skok = 0;
    cin >> a >> b >> n;
    long long nc[n];
    for(int i = 0; i < n; i++) cin >> nc[i];
    sort(nc, nc + n);
    for(int i = 0; i < n; i++) {
        skok += (nc[i] - a + 1) / 2 + (nc[i] - a + 1) % 2;
        a = nc[i] + 1;
    }
    skok += (b - a) / 2 + (b - a) % 2;
    cout << skok;
    return 0;
}
