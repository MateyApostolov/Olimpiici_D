#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, ans, p = 0;
    cin >> n >> k;
    int r1[n], r2[n];
    for(int i = 0; i < n; i++) {
        cin >> r1[i];
        r1[i] *= -1;
    }
    for(int i = 0; i < n; i++) {
        cin >> r2[i];
        r2[i] *= -1;
    }
    sort(r1, r1 + n);
    sort(r2, r2 + n);
    map <pair <int, int>, bool> mp;
    priority_queue <pair<int, pair<int, int>>> qu;
    qu.push({r1[0] + r2[0], {0, 0}});
    mp[{0, 0}] = true;
    while(p < k) {
        ans = qu.top().first;
        int h1 = qu.top().second.first, h2 = qu.top().second.second;
        qu.pop();
        if(h1 + 1 < n && !mp[{h1 + 1, h2}]) {
            qu.push({r1[h1 + 1] + r2[h2], {h1 + 1, h2}});
            mp[{h1 + 1, h2}] = true;
        }
        if(h2 + 1 < n && !mp[{h1, h2 + 1}]) {
            qu.push({r1[h1] + r2[h2 + 1], {h1, h2 + 1}});
            mp[{h1, h2 + 1}] = true;
        }
        p++;
    }
    cout << ans * -1;

    return 0;
}
