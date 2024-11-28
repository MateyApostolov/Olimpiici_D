#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, h, brp = 0;
    cin >> n >> m >> h;
    int hp[n][m];
    for(int r = 0; r < n; r++) {
        for(int k = 0; k < m; k++) {
            cin >> hp[r][k];
        }
    }
    for(int r = 0; r < n; r++) {
        for(int k = 0; k < m; k++) {
            if(hp[r][k] >= h) {
                brp++;
                continue;
            }
            bool t1 = false, t2 = false, t3 = false, t4 = false;
            for(int i = 0; i < k; i++) {
                if(hp[r][i] >= h) {
                    t1 = true;
                    break;
                }
            }
            for(int i = k + 1; i < m; i++) {
                if(hp[r][i] >= h) {
                    t2 = true;
                    break;
                }
            }
            for(int i = 0; i < r; i++) {
                if(hp[i][k] >= h) {
                    t3 = true;
                    break;
                }
            }
            for(int i = r + 1; i < n; i++) {
                if(hp[i][k] >= h) {
                    t4 = true;
                    break;
                }
            }
            if(t1 && t2 && t3 && t4) {
                brp++;
            }
        }
    }
    cout << brp;
    return 0;
}
