#include <bits/stdc++.h>
using namespace std;

const int maxc = 102;
int n, m, d2[maxc][maxc], brisl;
pair <int, int> p8[8] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, -1}, {-1, 1}, {-1, -1}, {1, 1}};

void isl(int x, int y) {
    if(d2[x][y] == 0) return;
    d2[x][y] = 0;
    for(int i = 0; i < 8; i++) {
        int px = x + p8[i].first;
        int py = y + p8[i].second;
        isl(px, py);
    }
    return;
}

int main () {
    cin >> n >> m;
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            cin >> d2[r][c];
        }
    }
    for(int r = 0; r <= n + 1; r++) {
        for(int c = 0; c <= m + 1; c++) {
            if(r == 1 || c == 1 || r == n || c == m) isl(r, c);
        }
    }
    for(int r = 0; r <= n + 1; r++) {
        for(int c = 0; c <= m; c++) {
            if(d2[r][c] == 0) continue;
            isl(r, c);
            brisl++;
        }
    }
    cout << brisl;
    return 0;
}
