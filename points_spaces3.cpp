#include <bits/stdc++.h>
using namespace std;

const int maxn = 3 * pow(10, 5) + 1;
consst int maxc = pow(10, 9) + 1;
int brp[maxn], brs[maxn], pref[maxc];

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
        mp[i].first.first += pow(10, 9);
        if(mp[i].first.second == 0) brsp++;
        if(mp[i].first.second == 1) {
            brs[mp[i].second] += brsp;
        }
        if(mp[i].first.second == 2) brsp--;
    }
    for(int i = 1; i <= 2 * pow(10, 9); i++) {
        pref[i] = pref[i - 1] + (mp[i].first.second % 2);
    }
    for(int i = 0; i < n; i++) cout << brs[i] << ' ';
    cout << '\n';
    for(int i = 0; i < q; i++) {
        cout << pref[r[i]] - pref[l[i] - 1];
    }
    return 0;
}

