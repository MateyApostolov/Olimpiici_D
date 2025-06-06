#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, w = 0, ans = 0, hi = 0;
    cin >> n >> m;
    pair<int, int> tv[n], bull[m];
    for(int i = 0; i < n; i++) cin >> tv[i].first >> tv[i].second;
    for(int i = 0; i < m; i++) cin >> bull[i].first >> bull[i].second;
    sort(bull, bull + m);
    for(int i = 0; i < n; i++) {
        w += tv[i].first;
        while(hi < m && w >= bull[hi].first) {
            if(tv[i].second >= bull[hi].second) ans++;
            else if(w == bull[hi].first && i + 1 < n && tv[i + 1].second >= bull[hi].second) ans++;
            hi++;
        }
    }
    cout << ans;
    return 0;
}
