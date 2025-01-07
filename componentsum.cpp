#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int n, m;
int nc[maxn][maxn], sum, maxsum, hx[4] = {-1, 1, 0, 0}, hy[4] = {0, 0, -1, 1};
bool used[maxn][maxn];

void rec (int x, int y) {
    sum += nc[x][y];
    used[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int nx = x + hx[i], ny = y + hy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !used[nx][ny]) rec(nx, ny);
    }
    return;
}

int main () {
    cin >> n >> m;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            cin >> nc[r][c];
        }
    }
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            cin >> used[r][c];
        }
    }
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(!used[r][c]) {
                rec(r, c);
            }
            maxsum = max(maxsum, sum);
            sum = 0;
        }
    }
    cout << maxsum;
    return 0;
}
