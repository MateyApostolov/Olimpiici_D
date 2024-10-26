#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) + 1;
int pref[maxn], br[maxn];

int main () {
    long long n, d, brt = 0;
    char c;
    cin >> n;
    vector <int> r, g, b;
    for(int i = 0; i < n; i++) {
        cin >> c >> d;
        if(c == 'r') r.push_back(d);
        if(c == 'g') g.push_back(d);
        if(c == 'b') b.push_back(d);
    }
    if(r.size() > b.size()) swap(r, b);
    if(g.size() > b.size()) swap(g, b);
    for(int i = 0; i < b.size(); i++) {
        br[b[i]]++;
    }
    for(int i = 1; i < maxn; i++) {
        pref[i] = pref[i - 1] + br[i];
    }
    for(int i1 = 0; i1 < r.size(); i1++) {
        for(int i2 = 0; i2 < g.size(); i2++) {
            brt = brt + pref[g[i2] + r[i1] - 1] - pref[abs(g[i2] - r[i1])];
        }
    }
    cout << brt;
    return 0;
}
