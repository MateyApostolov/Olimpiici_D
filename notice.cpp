#include <bits/stdc++.h>
using namespace std;

int pref[200][200], mess[200][200];

int main () {
    int l, h, n, x, y, b, a, brn = 0, y2, x2;
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
    cin >> y2 >> x2;
    for(int r = 1; r <= h; r++) {
        for(int k = 1; k <= l; k++) {
            pref[r][k] = pref[r - 1][k] + pref[r][k - 1] - pref[r - 1][k - 1] + mess[r][k];
        }
    }
    for(int x1 = 1; x1 + x2 - 1 <= h; x1++) {
        int r = x1 + x2 - 1;
        for(int y1 = 1; y1 + y2 - 1 <= l; y1++) {
            int k = y1 + y2 - 1;
            if(pref[r][k] - pref[x1 - 1][k] - pref[r][y1 - 1] + pref[x1 - 1][y1 - 1] == 0) {
                brn++;
            }
        }
    }
    cout << brn;
    return 0;
}
