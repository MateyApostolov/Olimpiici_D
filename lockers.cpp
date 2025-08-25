#include <bits/stdc++.h>
using namespace std;

unsigned long long n, s, l, r, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    r = n;
    if(((1 + n) * n) / 2 < s) {
        cout << 1;
        return 0;
    }
    while(l <= r) {
        m = l + (r - l) / 2;
        if(((1 + m) * m) / 2 <= s) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if((r * (r + 1)) / 2 + n - r > s) cout << n - r + 1;
    else cout << n - l + 1;
    return 0;
}

