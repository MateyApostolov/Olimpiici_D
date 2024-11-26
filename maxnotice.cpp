#include <bits/stdc++.h>
using namespace std;

int pref[102][102], mess[102][102];

int main () {
    int l, h, n, x, y, b, a, maxs = 0;
    cin >> l >> h >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> b >> a;
        x++;
        y++;
        for(int i1 = y; i1 < y + a; i1++) {
             for(int i2 = x; i2 < x + b; i2++) {
                mess[i1][i2] = 1;
             }
        }
    }
    for(int r = 1; r <= h; r++) {
        for(int k = 1; k <= l; k++) {
            pref[r][k] = pref[r - 1][k] + pref[r][k - 1] - pref[r - 1][k - 1] + mess[r][k];
        }
    }
    for(int x1 = 1; x1 <= h; x1++) {
        for(int y1 = 1; y1 <= l; y1++) {
            for(int x2 = x1; x2 <= h; x2++) {
                for(int y2 = y1; y2 <= l; y2++) {
                    if(pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1] == 0) {
                        maxs = max(maxs, (y2 - y1 + 1) * (x2 - x1 + 1));
                    }
                }
            }
        }
    }
    cout << maxs;
    return 0;
}
