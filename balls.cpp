#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, k, nc, maxc = LLONG_MIN, minc = LLONG_MAX;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        maxc = max(maxc, nc);
        minc = min(minc, nc);
    }
    cout << maxc - minc;
    return 0;
}
