#include <bits/stdc++.h>
using namespace std;

const int maxc = 2 * pow(10, 2) + 2;
int d2[maxc][maxc];
pair<int, int> p[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main () {
    int n, m, maxk = 0, brmk = 0;
    cin >> n >> m;
    for(int r = 0; r < n + 2; r++) {
        for(int c = 0; c < m + 2; c++) {
            if(r == 0 || r == n + 1 || c == 0 || c == m + 1) {
                d2[r][c] = 1;
                continue;
            }
            cin >> d2[r][c];
        }
    }
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            if(d2[r][c] == 1) continue;
            int brk = 0;
            vector <pair<int, int>> bfs;
            bfs.push_back({r, c});
            while(!bfs.empty()) {
                vector <pair<int, int>> help;
                for(int i = 0; i < bfs.size(); i++) {
                    for(int hp = 0; hp < 4; hp++) {
                        int x = bfs[i].first + p[hp].first;
                        int y = bfs[i].second + p[hp].second;
                        if(d2[x][y] == 1) continue;
                        help.push_back({x, y});
                        brk++;
                        d2[x][y] = 1;
                    }
                }
                bfs = help;
            }
            if(brk == maxk) {
                brmk++;
                continue;
            }
            if(brk > maxk) {
                maxk = brk;
                brmk = 1;
            }
        }
    }
    cout << maxk << ' ' << brmk;

    return 0;
}
