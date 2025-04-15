#include <bits/stdc++.h>
using namespace std;

int n;

bool ok (int num, int st) {
    long long mul = 1;
    for(int i = 0; i < st; i++) {
        mul = mul * num;
        if(mul > n) return false;
    }
    return true;
}

int main () {
    cin >> n;
    vector <pair<int, int>> c;
    for(int i = 2; i <= 30; i++) {
        int l = 0, r = n, mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(ok(mid, i)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ///cout << l << ' ' << r << ' ' << i << '\n';
        if(pow(r, i) == n) c.push_back({r, i});
    }
    cout << c.size() << '\n';
    if(c.size() == 0) return 0;
    for(int i = 0; i < c.size(); i++) {
        cout << c[i].first << ' ' << c[i].second << '\n';
    }
    return 0;
}
