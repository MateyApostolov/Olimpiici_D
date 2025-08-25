#include <bits/stdc++.h>
using namespace std;

long long n, s, l, r, m;

bool ok(long long num) {
    long long sum = ((1 + n) * n) / 2, hi = n;
    while(sum > s) {
        sum = sum - hi + 1;
        cout << sum << ' ' << hi << '\n';
        hi--;
    }
    if(n - hi + 1 > num) return true;
    return false;
}

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
        if(ok(m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
        cout << '\n' << l << ' ' << r << '\n';
    }
    cout << l;
    return 0;
}
