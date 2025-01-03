#include <bits/stdc++.h>
using namespace std;

int n;
map <string, long long> mp;

long long solve (string st) {
    if(mp.find(st) != mp.end()) return mp[st];
    long long s1, s2 = 0;
    if(st.empty()) return 1;
    s1 = solve(st.substr(1));
    if(st.size() > 1) {
        int c = (st[0] - '0') * 10 + (st[1] - '0');
        if(c >= 10 && c < 10 + n) s2 = solve(st.substr(2));
    }
    mp[st] = s1 + s2;
    return mp[st];
}

int main () {
    string st;
    cin >> n >> st;
    cout << solve(st);
    return 0;
}
