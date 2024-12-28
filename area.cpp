#include <bits/stdc++.h>
using namespace std;

const int maxrs = 502;
int r, c, sum, br, brwun;
pair <int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int nc[maxrs][maxrs];
bool wun[maxrs][maxrs];

void rec_matr (int rr, int cc) {
    nc[rr][cc] = -1;
    for(int i = 0; i < 4; i++) {
        int x = dir[i].first + rr, y = dir[i].second + cc;
        if(x < 0 || y < 0 || x > r + 1 || y > c + 1 || nc[x][y] != 0) continue;
        rec_matr(x, y);
    }
    return;
}


int main () {
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> nc[i][j];
            sum += nc[i][j];
        }
    }
    rec_matr(0, 0);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(nc[i][j] != -1) {
                wun[i][j] = true;
                br++;
            }
        }
    }
    for(int i = 1; i <= r + 1; i++) {
        for(int j = 1; j <= c + 1; j++) {
            int bro = wun[i - 1][j] + wun[i][j] + wun[i - 1][j - 1] + wun[i][j - 1];
            if(bro == 1) brwun++;
        }
    }
    cout << br << '\n' << sum << '\n' << brwun << '\n' << brwun - 4;
    return 0;
}
