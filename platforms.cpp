#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, brp = 0;
    cin >> n >> m;
    int pl[n + 2][m + 2];
    for(int i = 0; i < m + 2; i++) {
        pl[0][i] = 0;
        pl[n + 1][i] = 0;
    }
    for(int i = 0; i < n + 2; i++) {
        pl[i][0] = 0;
        pl[i][m + 1] = 0;
    }
    for(int r = 1; r < n + 1; r++) {
        for(int c = 1; c < m + 1; c++) {
            cin >> pl[r][c];
        }
    }
    for(int r = 1; r < n + 1; r++) {
        for(int c = 1; c < m + 1; c++) {
            if(pl[r][c] != 0) {
                brp++;
                int h = pl[r][c];
                pl[r][c] = 0;
                queue <pair<int, int>> bfs;
                bfs.push({r, c});
                while(!bfs.empty()) {
                    pair<int, int> help = bfs.front();
                    bfs.pop();
                    int r1 = help.first, c1 = help.second;
                    if(pl[r1][c1 + 1] != 0 && pl[r1][c1 + 1] == h) {
                        pl[r1][c1 + 1] = 0;
                        bfs.push({r1, c1 + 1});
                    }
                    if(pl[r1][c1 - 1] != 0 && pl[r1][c1 - 1] == h) {
                        pl[r1][c1 - 1] = 0;
                        bfs.push({r1, c1 - 1});
                    }
                    if(pl[r1 + 1][c1] != 0 && pl[r1 + 1][c1] == h) {
                        pl[r1 + 1][c1] = 0;
                        bfs.push({r1 + 1, c1});
                    }
                    if(pl[r1 - 1][c1] != 0 && pl[r1 - 1][c1] == h) {
                        pl[r1 - 1][c1] = 0;
                        bfs.push({r1 - 1, c1});
                    }
                }
            }
        }
    }
    cout << brp;

    return 0;
}
