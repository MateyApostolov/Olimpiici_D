#include <bits/stdc++.h>
using namespace std;

int main () {
    int m, n, x1 = 1, x2 = 1, y1 = 1, y2 = 1, brz = 0, p1 = 0, p2 = 0;
    cin >> m >> n;
    for(int i = 0; i < n * m; i++) {
        if(p1 == 0) {
            if(x1 < n) x1++;
            else {
                y1++;
                p1 = 1;
            }
        } else if(p1 == 1) {
            if(x1 > 1) x1--;
            else {
                y1++;
                p1 = 0;
            }
        }
        if(p2 == 0) {
            if(y2 < m) y2++;
            else {
                x2++;
                p2 = 1;
            }
        } else if(p2 == 1) {
            if(y2 > 1) y2--;
            else {
                x2++;
                p2 = 0;
            }
        }
        ///cout << x1 << ' ' << y1 << ':' << x2 << ' ' << y2 << '\n';
        if(x1 == x2 && y1 == y2) brz++;
    }
    cout << brz;
    return 0;
}
