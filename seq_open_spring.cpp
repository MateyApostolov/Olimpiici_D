#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t, tc;
    cin >> n;
    int nc[n + 1], ls[n + 1], rs[n + 1];
    stack <pair<int, int>> l, r;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
        while(!l.empty() && nc[i] >= l.top().first) l.pop();
        if(!l.empty()) ls[i] = l.top().second;
        else ls[i] = 0;
        l.push({nc[i], i});
    }
    for(int i = n; i >= 1; i--) {
        while(!r.empty() && nc[i] >= r.top().first) r.pop();
        if(!r.empty()) rs[i] = r.top().second;
        else rs[i] = 0;
        r.push({nc[i], i});
    }
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> tc;
        cout << ls[tc] << ' ' << rs[tc] << '\n';
    }

    return 0;
}
