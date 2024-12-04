#include <bits/stdc++.h>
using namespace std;

int pref2[1002][1002];

int main () {
    int m, n, k, num, brh = 0, brv = 0;
    cin >> m >> n >> k;
    for(int r = 1; r <= m; r++) {
        for(int c = 1; c <= n; c++) {
            cin >> num;
            pref2[r][c] = pref2[r - 1][c] + pref2[r][c - 1] - pref2[r - 1][c - 1] + num;
        }
    }
    int kh = k + 2, kv = 3;
    for(int r = 1; r + kh <= m; r++) {
        for(int c = 1; c + kv <= n; c++) {
            cout << r << ' ' << c << ' ';
            if(pref2[r + kh][c + kv] - pref2[r + kh][c - 1] - pref2[r - 1][c + kv] + pref2[r - 1][c - 1] == 0)  {
                brv++;
                cout << 'f';
            }
            cout << '\n';
        }
    }
    cout << '\n';
    for(int r = 1; r + kv <= m; r++) {
        for(int c = 1; c + kh <= n; c++) {
            cout << r << ' ' << c << ' ';
            if(pref2[r + kv][c + kh] - pref2[r + kv][c - 1] - pref2[r - 1][c + kh] + pref2[r - 1][c - 1] == 0) {
                brh++;
                cout << 'f';
            }
            cout << '\n';
        }
    }
    cout << brh << ' ' << brv;
    return 0;
}
