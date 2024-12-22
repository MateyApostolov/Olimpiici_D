#include <bits/stdc++.h>
using namespace std;

const int maxn = 201;
const int hx[4] = {0, 0, -1, 1};
const int hy[4] = {1, -1, 0, 0};
int n, m, br;
bool t[maxn][maxn], use[maxn][maxn];

void rec (int x, int y) {
    use[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int nx = x + hx[i];
        int ny = y + hy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !t[nx][ny] && !use[nx][ny]) rec(nx, ny);
    }
}

int main () {
    cin >> n >> m;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            cin >> t[r][c];
        }
    }
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(!t[r][c] && !use[r][c]) {;
                rec(r, c);
                br++;
            }
        }
    }
    cout << br;
    return 0;
}


