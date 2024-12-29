#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
pair <int, int> dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool used[maxn + 2][maxn + 2];

void set_ramka () {
    for(int i = 0; i <= maxn + 1; i++) {
        used[0][i] = true;
        used[i][0] = true;
        used[i][maxn + 1] = true;
        used[maxn + 1][i] = true;
    }
}

void rec_matr (int rr, int cc) {
    used[rr][cc] = true;
    for(int i = 0; i < 4; i++) {
        int x = dir[i].first + rr, y = dir[i].second + cc;
        if(!used[x][y]) rec_matr(x, y);
    }
    return;
}

int main () {
    set_ramka();
    int n, m, kx, ky;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> kx >> ky;
        if(kx <= maxn && ky <= maxn) used[kx][ky] = true;
    }
    rec_matr(1, 1);
    if(n < maxn) {
        if(used[n][n]) cout << "YES";
        else cout << "NO";
        return 0;
    }
    if(used[maxn][maxn]) cout << "YES";
    else cout << "NO";
    return 0;
}
