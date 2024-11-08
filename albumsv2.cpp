#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, c, br = 0;
    cin >> n >> m;
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> c;
        mp[c]++;
    }
    for(int i = 0; i < m; i++) {
        cin >> c;
        mp[c]--;
        if(mp[c] == 0) {
            br++;
        }
    }
    cout << br << '\n';
    sort(mp.begin(), mp.end());
    for(auto x : mp) {
        if(x.second == 0) {
            cout << x.first << ' ';
        }
    }
    return 0;
}

