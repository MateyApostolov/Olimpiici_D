#include <bits/stdc++.h>
using namespace std;


int main () {
    int m, n, maxr = 0, brv = 0, brh = 0, brkv, maxh = 0, maxv = 0;
    cin >> m >> n;
    int nc[m + 1][n + 1];
    for(int r = 1; r <= m; r++) {
        for(int c = 1; c <= n; c++) {
            cin >> nc[r][c];
        }
    }
    vector <int> h, v;
    h.push_back(0);
    for(int r = 1; r < m; r++) {
        bool t = true;
        for(int c = 1; c <= n; c++) {
            if(nc[r][c] == nc[r + 1][c]) {
                t = false;
            }
        }
        if(t) {
            brh++;
            h.push_back(r);
        }
    }
    h.push_back(m);
    v.push_back(0);
    for(int c = 1; c < n; c++) {
        bool t = true;
        for(int r = 1; r <= m; r++) {
            if(nc[r][c] == nc[r][c + 1]) {
                t = false;
            }
        }
        if(t) {
            brv++;
            v.push_back(c);
        }
    }
    v.push_back(n);
    for(int i = 1; i < h.size(); i++) {
        maxh = max(maxh, h[i] - h[i - 1]);
    }
    for(int i = 1; i < v.size(); i++) {
        maxv = max(maxv, v[i] - v[i - 1]);
    }
    brkv = (brh + 1) * (brv + 1);
    cout << brh << ' ' << brv << ' ' << brkv << ' ' << maxh * maxv;
    return 0;
}

