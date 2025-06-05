#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, t, p, maxh = 0, p0 = 0, prp = 0, sumc = 0;
    cin >> n;
    stack <int> st;
    map <int, int> mp, m1;
    for(int i = 0; i < 2 * n; i++) {
        cin >> t >> p;
        if(t == 1) {
            st.push(p);
        }
        else {
            for(auto x : m1) prp += x.second;
            p0++;
            int sts = st.size();
            maxh = max(maxh, sts);
            int hp = st.top(), s = p0 * (p - hp) - prp;
            st.pop();
            m1[p0] += s;
        }
        if(st.empty()) {
            p0 = 0;
            prp = 0;
            for(auto x : m1) mp[x.first] += x.second;
            m1.clear();
        }
    }
    for(auto x : mp) sumc += x.second;
    cout << maxh << ' ' << sumc << '\n';
    for(auto x : mp) cout << x.second << ' ';

    return 0;
}
