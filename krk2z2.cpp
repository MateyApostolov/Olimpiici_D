#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, br = 0, brk;
    cin >> n;
    brk = n;
    int r1[n], r2[n];
    bool p[n] = {};
    for(int i = 0; i < n; i++) {
        cin >> r1[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> r2[i];
    }
    for(int i1 = 0; i1 < n; i1 += 1 + br) {
        br = 0;
        int h = 0;
        for(int i2 = 0; i2 < n; i2++) {
            if(r2[i2] == r1[i1]) {
                h = i2;
                break;
            }
        }
        while(h + br < n && r2[h + br] == r1[i1 + br]) {
            br++;
        }
        br--;
        brk -= br;
        ///cout << brk << "\n";
    }
    cout << brk;
    return 0;
}
