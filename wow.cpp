#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, brs = 0, bri = 0, brm = 0, hi = 0, brt = 0;
    cin >> n;
    pair<int, int> nc[n];
    for(int i = 0; i < n; i++) {
        cin >> nc[i].first;
    }
    while(true) {
        nc[hi].second++;
        hi = nc[hi].first;
        brt++;
        if(brt > 20000) break;
    }
    for(int i = 0; i < n; i++) {
        if(nc[i].second == 0) brs++;
        if(nc[i].second == 1) brm++;
        if(nc[i].second > 1) bri++;
    }
    cout << brm << ' ' << bri << ' ' << brs;
    return 0;
}
