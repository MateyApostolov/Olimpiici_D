#include <bits/stdc++.h>
using namespace std;

const int maxn = 202;
long long mm[maxn][maxn][maxn + maxn], d2_62 = 1;

int dp (int x, int y, int h) {
    if(x == 1 && y == 1 && h == 1) return 1;
    if(x == 0 || y == 0 || h == 0 ) return 0;
    if(mm[x][y][h] != 0) return mm[x][y][h];
    int v1, v2, v3;
    v1 = dp(x - 1, y, h - 1);
    v2 = dp(x, y - 1, h - 1);
    v3 = dp(x - 1, y - 1, h - 1);
    mm[x][y][h] = (v1 + v2 + v3) % d2_62;
    return mm[x][y][h];
}


int main () {
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 0; i < 62; i++) d2_62 *= 2;
    cout << dp(n, m, p);
    return 0;
}

