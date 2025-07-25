#include <bits/stdc++.h>
using namespace std;

const int maxs = pow(10, 5) + 2;
int pref[maxs];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, w, hi;
    cin >> s >> w;
    int q, a, b;
    for(int i = 0; i < s.size(); i++) {
        int h = -1;
        hi.clear();
        while(i + h + 1 < s.size() && h + 1 < w.size() && s[i + h + 1] == w[h + 1]) {
            h++;
            hi.push_back(s[i + h]);
        }
       ///cout << hi << '\n';
        if(hi == w) pref[i]++;
        if(i != 0) pref[i] += pref[i - 1];
    }
    ///for(int i = 0; i < s.size(); i++) cout << pref[i] << ' ';
    ///cout << '\n' << '\n';
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        if(b - a + 1 < 2 * w.size()) {
            cout << 0 << '\n';
            continue;
        }
        int h;
        if(a <= 1) h = pref[b - w.size()];
        else h = pref[b - w.size()] - pref[a - 2];
        cout << (h * (h - 1)) / 2 << '\n';
    }
    return 0;
}
