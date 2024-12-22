#include <bits/stdc++.h>
using namespace std;

const int maxn = 201;
int n, m, br;
bool t[maxn][maxn], use[maxn][maxn];

void rec (int x, int y) {
    use[x][y] = true;
    if(x - 1 >= 0 && !t[x - 1][y] && !use[x - 1][y]) rec(x - 1, y);
    if(x + 1 < n && !t[x + 1][y] && !use[x + 1][y]) rec(x + 1, y);
    if(y - 1 >= 0 && !t[x][y - 1] && !use[x][y - 1]) rec(x, y - 1);
    if(y + 1 < m && !t[x][y + 1] && !use[x][y + 1]) rec(x, y + 1);
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
            if(!t[r][c] && !use[r][c]) {
                rec(r, c);
                br++;
            }
        }
    }
    cout << br;
    return 0;
}

