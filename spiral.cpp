#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, k, x = 0, y = 0, p = 1, hi = 0, brs = 0, maxh = 0;
    cin >> n >> m >> k;
    int nc[n][m], pref[n * m + 1] = {};
    vector <int> sp;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            cin >> nc[r][c];
        }
    }
    sp.push_back(nc[0][0]);
    nc[0][0] = -1;
    while(sp.size() < n * m) {
        if(p == 1) {
            if(y + 1 < m && nc[x][y + 1] != -1) {
                sp.push_back(nc[x][y + 1]);
                nc[x][y + 1] = -1;
                y++;
            }
            else {
                p++;
            }
            continue;
        }
        if(p == 2) {
            if(x + 1 < n && nc[x + 1][y] != -1) {
                sp.push_back(nc[x + 1][y]);
                nc[x + 1][y] = -1;
                x++;
            }
            else {
                p++;
            }
            continue;
        }
        if(p == 3) {
            if(y - 1 >= 0 && nc[x][y - 1] != -1) {
                sp.push_back(nc[x][y - 1]);
                nc[x][y - 1] = -1;
                y--;
            }
            else {
                p++;
            }
            continue;
        }
        if(p == 4) {
            if(x - 1 >= 0 && nc[x - 1][y] != -1) {
                sp.push_back(nc[x - 1][y]);
                nc[x - 1][y] = -1;
                x--;
            }
            else {
                p = 1;
            }
            continue;
        }
    }
    ///for(int i = 0; i < sp.size(); i++) cout << sp[i] << ' ';
    while(hi < sp.size()) {
        if(hi + k > sp.size()) {
            brs++;
            break;
        }
        int i;
        for(i = k; i > 0; i--) {
            if(sp[hi + i] == 0) break;

        }
        hi += i;
        brs++;
    }
    for(int i = 1; i <= sp.size(); i++) {
        pref[i] = pref[i - 1] + 1 - sp[i];
    }
    for(int i = 1; i <= sp.size() - k; i++) {
        maxh = max(maxh, pref[i + k] - pref[i]);
    }
    cout << brs << ' ' << maxh;
    return 0;
}
