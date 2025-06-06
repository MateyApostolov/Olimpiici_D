#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000;

int main () {
    int n, m, x, y, ans = 0;
    cin >> n >> m;
    pair<int, int> tv[maxn];
    tv[0] = {0, 0};
    for(int i = 1; i <= n; i++) {
        cin >> x >> tv[i].second;
        tv[i].first = tv[i - 1].first + x;
    }
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        int l = 0, r = maxn, mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(tv[mid].first <= x) l = mid + 1;
            else r = mid - 1;
        }
        if(tv[l].first < x) continue;
        if(tv[l].second >= y) ans++;
    }
    cout << ans;
    return 0;
}
