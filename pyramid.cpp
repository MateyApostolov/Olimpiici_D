#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 3);
int pyr[maxn][maxn * 2 - 1];

int main () {
    int n, p = 1, num = 1, x, y = 0, h = 0;
    cin >> n;
    x = n - 1;
    pyr[x][y] = num;
    num++;
    while(h < 3 && num <= n * n) {
        ///cout << x << ' ' << y << '\n';
        if(p == 1) {
            if(y + 1 < n * 2 - 1 && pyr[x][y + 1] == 0) {
                y++;
                pyr[x][y] = num;
                num++;
                h = 0;
            } else {
                p = 2;
                h++;
            }
            continue;
        }
        if(p == 2) {
            if(y - 1 >= 0 && x - 1 >= 0 && (pyr[x - 1][y - 1] == 0 && ((pyr[x - 1][y] == 0 || pyr[x][y - 1] == 0)))) {
                x--;
                y--;
                pyr[x][y] = num;
                num++;
                h = 0;
            } else {
                p = 3;
                h++;
            }
            continue;
        }
        if(p == 3) {
            if(y - 1 >= 0 && x + 1 < n && (pyr[x + 1][y - 1] == 0 && ((pyr[x + 1][y] == 0 || pyr[x][y - 1] == 0)))) {
                x++;
                y--;
                pyr[x][y] = num;
                num++;
                h = 0;
            } else {
                p = 1;
                h++;
            }
            continue;
        }
    }
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < 2 * n - 1; c++) {
            if(pyr[r][c] != 0) cout << pyr[r][c] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
