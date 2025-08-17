#include <bits/stdc++.h>
using namespace std;

const int maxs = pow(10, 5) + 2;
long long pref1[maxs], pref2[maxs];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, w;
    cin >> s >> w;
    long long q, l, r;
    cin >> q;
    for(int i = 1; i <= s.size(); i++) {
        bool t = true;
        for(int x = 0; x < w.size(); x++) {
            if(s[i + x - 1] != w[x]) {
                t = false;
                break;
            }
        }
        pref1[i] = pref1[i - 1] + t;
        if(i >= w.size()) pref2[i] = pref2[i - 1] + t * pref1[i - w.size()];
    }
    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        if(r - l + 1 >= 2 * w.size()) {
            long long li, ri, ans1, ans2;
            li = l + w.size() - 1;
            ri = r - w.size() + 1;
            ans1 = pref2[ri] - pref2[li];
            ans2 = (pref1[ri] - pref1[li]) * pref1[l - 1];
            cout << ans1 - ans2 << '\n';

        } else cout << 0 << '\n';
    }

    return 0;
}
