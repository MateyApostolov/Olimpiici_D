#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, nc, ans = 0, pr;
    cin >> n;
    bool t = false;
    map <int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        mp[nc]++;
    }
    for(auto x : mp) {
        ans += x.second / 4;
        mp[x.first] %= 4;
    }
    for(auto x : mp) mp[x.first] /= 2;
    for(auto x : mp) {
        if(x.second == 0) continue;
        if(!t) {
            pr = x.first;
            t = true;
        } else {
            if(x.first <= 2 * pr) {
                ans++;
                t = false;
            } else pr = x.first;
        }
    }
    cout << ans;
    return 0;
}
