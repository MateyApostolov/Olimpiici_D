#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, ans;
    int q;
    cin >> s >> q;
    pair <pair<int, int>, int> nc[q];
    for(int i = 0;  i < q; i++) {
        cin >> nc[i].first.first >> nc[i].first.second >> nc[i].second;
        nc[i].second %= 26;
    }
    sort(nc, nc + q);
    int sch[s.size() + 1], hi = 0, d = 0;
    priority_queue <pair<int, int>> h;
    for(int i = 1; i <= s.size(); i++) {
        while(i == nc[hi].first.first) {
            d += nc[hi].second;
            h.push({nc[hi].first.second * -1, nc[hi].second});
            hi++;
        }
        sch[i] = d;
        while(!h.empty() && i == h.top().first * -1) {
            d -= h.top().second;
            h.pop();
        }
    }
    for(int i = 0; i < s.size(); i++) {
        s[i] = (s[i] - 'a' + sch[i + 1]) % 26 + 'a';
    }
    ans = s;
    cout << ans;
    return 0;
}
