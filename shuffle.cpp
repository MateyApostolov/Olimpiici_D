#include <bits/stdc++.h>
using namespace std;

const int maxn = 51;
bool used[maxn];

int main () {
    string f, s;
    cin >> f >> s;
    int brs = 0;
    for(int fi = 0; fi < f.size(); fi++) {
        int nmg = 26, hi = 0;
        for(int si = 0; si < s.size(); si++) {
            if(used[si]) continue;
            if(s[si] - f[fi] >= 0 && nmg >= s[si] - f[fi]) {
                nmg = s[si] - f[fi];
                hi = si;
            } else if(s[si] - f[fi] < 0 && nmg >= s[si] - f[fi] + 26) {
                nmg = s[si] - f[fi] + 26;
                hi = si;
            }
        }
        used[hi] = true;
        brs += nmg;
    }
    cout << brs;
    return 0;
}
