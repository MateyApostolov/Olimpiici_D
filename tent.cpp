#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 6) + 1;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, brt = 0;
    cin >> n >> m;
    int mt[n + 2][m + 2];
    for(int i = 0; i < n + 2; i++) {
        mt[i][0] = maxc;
        mt[i][m + 1] = maxc;
    }
    for(int i = 0; i < m + 2; i++) {
        mt[0][i] = maxc;
        mt[n + 1][i] = maxc;
    }
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            cin >> mt[r][c];
        }
    }
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            int hi = 0;
            while(mt[r][c] >= mt[r + hi][c + hi] &&
                  mt[r][c] >= mt[r + hi][c - hi] &&
                  mt[r][c] >= mt[r - hi][c + hi] &&
                  mt[r][c] >= mt[r - hi][c - hi]) hi++;
            brt += hi;
        }
    }
    cout << brt;
    return 0;
}
