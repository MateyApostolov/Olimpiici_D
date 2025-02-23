#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    pair <int, int> cs[m];
    int st[n] = {};
    for(int i = 0; i < m; i++) {
        cin >> cs[i].first >> cs[i].second;
        cs[i].second = -cs[i].second;
    }
    sort(cs, cs + m);
    for(int i = 0; i < m; i++) {
        int minm = pow(10, 5), hi = 0;
        for(int x = 0; x < n; x++) {
            if(minm > st[x]) {
                minm = st[x];
                hi = x;
            }
            if(st[x] <= cs[i].first) {
                hi = x;
                break;
            }
        }
        st[hi] = max(cs[i].first, st[hi]) - cs[i].second;
    }
    int maxm = 0, hi = 0;
    for(int i = 0; i < n; i++) {
        if(maxm <= st[i]) {
            maxm = st[i];
            hi = i;
        }
    }
    cout << maxm << ' ' << hi + 1;
    return 0;
}
