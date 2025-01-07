#include <bits/stdc++.h>
using namespace std;

int main () {
    long long x1, y1, x2, y2, n, r, s;
    char d, p;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for(int i = 0; i < n; i++) {
        cin >> d >> r >> p;
        if(p == 'L') {
            x1 = r;
        } else if(p == 'R') {
            x2 = r;
        } else if(p == 'T') {
            y2 = r;
        } else if(p == 'B') {
            y1 = r;
        }
    }
    s = (x2 - x1) * (y2 - y1);
    cout << s;

    return 0;
}
