#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 6) + 1;
int l[maxn], r[maxn];

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
        l[nc[i].first.first] += nc[i].second;
        r[nc[i].first.second] += nc[i].second;
    }
    int d = 0;
    for(int i = 1; i <= s.size(); i++) {
        d += l[i];
        s[i - 1] = (s[i - 1] - 'a' + d) % 26 + 'a';
        d -= r[i];
    }
    ans = s;
    for(int i1 = 0; i1 < q; i1++) {
        string hs = s;
        for(int i2 = nc[i1].first.first - 1; i2 <= nc[i1].first.second - 1; i2++) {
            int hb = hs[i2] - 'a' - nc[i1].second;
            if(hb < 0) {
                hb += 26;
            }
            hs[i2] = hb + 'a';
        }
        ans = min(ans, hs);
    }
    cout << ans;
    return 0;
}
