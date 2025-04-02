#include <bits/stdc++.h>
using namespace std;

const int maxn = 3 * pow(10, 5) + 1;
int brp[maxn], brs[maxn], pref[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, brsp = 0, nc, brsi = 0, brt = 0;
    cin >> n >> q;
    int l[q], r[q];
    vector <pair<pair<int, int>, int>> mp;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        mp.push_back({{nc, 1}, i});
    }
    for(int i = 0; i < q; i++) {
        cin >> l[i];
        mp.push_back({{l[i], 0}, i});
    }
    for(int i = 0; i < q; i++) {
        cin >> r[i];
        mp.push_back({{r[i], 2}, i});
    }
    sort(mp.begin(), mp.end());
    for(int i = 0; i < n + 2 * q; i++) {
        if(mp[i].first.second == 0) brsp++;
        if(mp[i].first.second == 1) {
            brs[mp[i].second] += brsp;
        }
        if(mp[i].first.second == 2) brsp--;
    }
    for(int i = 0; i < n + 2 * q; i++) {
        if(mp[i].first.second == 0) {
            pref[mp[i].second] = brt;
        }
        if(mp[i].first.second == 1) {
            brt++;
        }
        if(mp[i].first.second == 2) {
            brp[mp[i].second] = brt - pref[mp[i].second];
        }
    }
    for(int i = 0; i < n; i++) cout << brs[i] << ' ';
    cout << '\n';
    for(int i = 0; i < q; i++) cout << brp[i] << ' ';
    return 0;
}

