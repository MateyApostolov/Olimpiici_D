#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 6) + 1, maxd = 1002;
int mt[maxd][maxd], nm[maxd][maxd];

void diag (int x, int y, int px, int py) {
    stack <pair<int, int>> st;
    st.push({maxc, x - px});
    while(mt[x][y] != 0) {
        while(st.top().first <= mt[x][y]) st.pop();
        if(nm[x][y] == 0) nm[x][y] =abs(x - st.top().second);
        else nm[x][y] = min(nm[x][y], abs(x - st.top().second));
        if(st.top().first != mt[x][y]) st.push({mt[x][y], x});
        x += px;
        y += py;
    }

    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, brt = 0;
    cin >> n >> m;
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            cin >> mt[r][c];
        }
    }
    for(int i = 1; i <= m; i++) {
        diag(1, i, 1, 1);
        diag(1, i, 1, -1);
        diag(n, i, -1, -1);
        diag(n, i, -1, 1);
    }
    for(int i = 1; i <= n; i++) {
        diag(i, 1, 1, 1);
        diag(i, 1, -1, 1);
        diag(i, m, -1, -1);
        diag(i, m, 1, -1);
    }
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            brt += nm[r][c];
        }
    }
    cout << brt;
    return 0;
}
