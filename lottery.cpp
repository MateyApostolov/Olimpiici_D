#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> mp;

void eratosten (vector <int> del, int p, int q) {
    for(int d = 0; d < del.size(); d++) {
        int beg = p / del[d] * del[d];
        if(p % del[d] != 0) beg += del[d];
        for(int h = beg; h <= q; h += del[d]) {
            mp[h]++;
        }
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, p, q, nc, brd = 0;
    cin >> n >> k;
    vector <int> del;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        del.push_back(nc);
    }
    cin >> p >> q;
    eratosten(del, p, q);
    for(auto x : mp) {
        if(x.first >= p && x.first <= q && x.second == k) brd++;
    }
    cout << brd;
    return 0;
}
