#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;
int s[maxn][maxn];
pair <int, int> help[3] = {{1, 3}, {4, 6}, {7, 9}};

bool poss (int x, int y, int nc) {
    for(int i = 1; i < maxn; i++) {
        if(s[x][i] == nc) return false;
    }
    for(int i = 1; i < maxn; i++) {
        if(s[i][y] == nc) return false;
    }
    for(int i1 = 0; i1 < 3; i1++) {
        if(!(x >= help[i1].first && x <= help[i1].second)) continue;
        for(int i2 = 0; i2 < 3; i2++) {
            if(!(y >= help[i2].first && y <= help[i2].second)) continue;
            for(int r = help[i1].first; r <= help[i1].second; r++) {
                for(int c = help[i2].first; c <= help[i2].second; c++) {
                    if(s[r][c] == nc) return false;
                }
            }
        }
    }
    return true;
}

bool solve (int x, int y) {
    if(x == 9 && y == 10) return true;
    if(y == 10) {
        x++;
        y = 1;
    }
    if(s[x][y] != 0) return solve(x, y + 1);
    for(int i = 1; i < maxn; i++) {
        if(poss(x, y, i)) {
            s[x][y] = i;
            if(solve(x, y + 1)) return true;
        }
    }
    s[x][y] = 0;
    return false;
 }

int main () {
    char sym;
    for(int x = 1; x < maxn; x++) {
        for(int y = 1; y < maxn; y++) {
            cin >> sym;
            s[x][y] = sym - '0';
        }
    }
    if(solve(1, 1)) {
        for(int x = 1; x < maxn; x++) {
            for(int y = 1; y < maxn; y++) {
                cout << s[x][y] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
