#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int pref[maxn];

int main () {
    int n, k, nc, maxs;
    cin >> n >> k;
    cin >> nc;
    pref[0] = nc;
    for(int i = 1; i < n; i++) {
        cin >> nc;
        pref[i] = pref[i - 1] + nc;
    }
    maxs = pref[k - 1];
    for(int i = k; i < n; i++) {
        maxs = max(maxs, pref[i] - pref[i - k]);
    }
    cout << maxs;

    return 0;
}
