#include <bits/stdc++.h>
using namespace std;

int pref2[1001][1001];

int main () {
    int m, n, k, num, maxr = 0;
    cin >> m >> n >> k;
    for(int r = 1; r <= m; r++) {
        for(int c = 1; c <= n; c++) {
            cin >> num;
            pref2[r][c] = pref2[r - 1][c] + pref2[r][c - 1] - pref2[r - 1][c - 1] + num;
        }
    }
    for(int r = 1; r + k - 1 <= m; r++) {
        for(int c = 1; c + k - 1 <= n; c++) {
            maxr = max(maxr, pref2[r + k - 1][c + k - 1] - (pref2[r + k - 1][c - 1] + pref2[r - 1][c + k - 1] - pref2[r - 1][c - 1]));
        }
    }
    cout << pref2[m][n] - maxr;
    return 0;
}
