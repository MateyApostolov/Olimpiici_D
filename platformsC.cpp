#include <bits/stdc++.h>
using namespace std;

const int maxc = 1002;
int d2[maxc][maxc];

int dfs (int bx, int by, int num) {
    int br0 = 0;
    if(d2[bx][by] != num) return br0;
    d2[bx][by] = -1;
    br0 += dfs(bx + 1, by, num);
    br0 += dfs(bx, by + 1, num);
    br0 += dfs(bx - 1, by, num);
    br0 += dfs(bx, by - 1, num);
    return br0 + 1;
}

int main () {
    int n, m, x, y, brpl;
    cin >> n >> m;
    brpl = n * m;
    for(int r = 0; r <= n + 1; r++) {
        for(int c = 0; c <= m + 1; c++) {
            if(r == 0 || c == 0 || r == n + 1 || c == m + 1) d2[r][c] = -1;
            else cin >> d2[r][c];
        }
    }
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            if(d2[r][c] == -1) continue;
            int help = dfs(r, c, d2[r][c]);
            brpl = brpl - help + 1;
        }
    }
    cout << brpl;
    return 0;
}


