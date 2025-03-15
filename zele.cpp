#include <bits/stdc++.h>
using namespace std;

int main () {
    long long h, w, k, n, m, nc, zas = 0;
    cin >> h >> w >> k >> n >> m;
    vector <long long> rv, rc;
    rv.push_back(0);
    rc.push_back(0);
    for(int i = 0; i < n; i++) {
        cin >> nc;
        rv.push_back(nc);
    }
    for(int i = 0; i < m; i++) {
        cin >> nc;
        rc.push_back(nc);
    }
    rv.push_back(h);
    rc.push_back(w);
    for(int i = 1; i < rv.size(); i++) {
        for(int x = 1; x < rc.size(); x++) {
            long long r = rv[i] - rv[i - 1], c = rc[x] - rc[x - 1];
            if(2 * (k + 1) < r && 2 * (k + 1) < c)  {
                zas += r * c - (r - 2 * (k + 1)) * (c - 2 * (k + 1));
            } else zas += r * c;
        }
    }
    cout << zas;
    return 0;
}
