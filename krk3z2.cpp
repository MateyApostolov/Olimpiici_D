#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5) + 1, maxk = pow(10, 4) + 1;
bool isc[maxk][maxn];
int rr[maxk], n, k;

bool check_r () {
    for(int i = 0; i < k; i++) {
        if(rr[i] == 0) {
            return false;
        }
    }
    return true;
}

int main () {
    cin >> n >> k;
    string s;
    stringstream ss;
    bool ch = false;
    int r = 1, minr = n, minl = 1, nc;
    for(int i1 = 0; i1 < k; i1++) {
        for(int i2 = 0; i2 < k; i2++) {
            cin >> nc;
            isc[i1][nc] = true;
        }
    }
    for(int l = 1; l <= n; l++) {
        while(r <= n && !ch) {
            for(int i = 0; i < k; i++) {
                if(isc[i][r]) {
                    rr[i]++;
                }
            }
            ch = check_r();
            r++;
        }
        if(ch && r - l - 1 < minr - minl) {
            minr = r - 1;
            minl = l;
        }
        if(r == n + 1 && !ch) break;
        for(int i = 0; i < k; i++) {
            if(isc[i][l]) {
                rr[i]--;
            }
        }
        ch = check_r();
    }
    cout << minl << ' ' << minr;
    return 0;
}
