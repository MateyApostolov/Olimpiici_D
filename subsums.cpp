#include <bits/stdc++.h>
using namespace std;

map <int, bool> dp;

int main () {
    int n, c;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        map <int, bool> h;
        h[c] = true;
        for(auto x : dp) {
            h[x.first + c] = true;
            h[x.first] = true;
        }
        dp = h;
    }
    cout << dp.size();
    return 0;
}

