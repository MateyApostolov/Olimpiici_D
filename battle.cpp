#include <bits/stdc++.h>
using namespace std;

int pref2[2000][2000];

int main () {
    int m, n, k, num, brh = 0, brv = 0;
    cin >> m >> n >> k;
    for(int r = 2; r <= m + 1; r++) {
        for(int c = 2; c <= n + 1; c++) {
            cin >> num;
            pref2[r][c] = pref2[r - 1][c] + pref2[r][c - 1] - pref2[r - 1][c - 1] + num;
        }
    }
    for(int r = 2; r <= m + 1; r++) {
        pref2[r][n + 2] = pref2[r - 1][n + 2] + pref2[r][n + 2 - 1] - pref2[r - 1][n + 2 - 1];
    }
    for(int c = 2; c <= n + 2; c++) {
        pref2[m + 2][c] = pref2[m + 2 - 1][c] + pref2[m + 2][c - 1] - pref2[m + 2 - 1][c - 1];
    }
    /*for(int r = 0; r <= m + 2; r++) {
        for(int c = 0; c <= n + 2; c++) {
            cout << pref2[r][c] << ' ';
        }
        cout << '\n';
    }*/
    for(int r = 2; r <= m + 1; r++) {
        for(int c = 2; c + k - 1 <= n + 1; c++) {
            int res = pref2[r + 1][c + k] - pref2[r + 1][c - 2] - pref2[r - 2][c + k] + pref2[r - 2][c - 2];
            ///cout << r << ' ' << c << ' ' << res << ' ';
            if(res == 0)  {
                brh++;
                ///cout << 'f';
            }
            ///cout << '\n';
        }
    }
    ///cout << '\n';
    for(int r = 2; r + k - 1<= m + 1; r++) {
        for(int c = 2; c <= n + 1; c++) {
            int res = pref2[r + k][c + 1] - pref2[r - 2][c + 1] - pref2[r + k][c - 2] + pref2[r - 2][c - 2];
            ///cout << r << ' ' << c << ' ' << res << ' ';
            if(res == 0)  {
                brv++;
               /// cout << 'f';
            }
            ///cout << '\n';
        }
    }
    cout << brh << ' ' << brv;
    return 0;
}
