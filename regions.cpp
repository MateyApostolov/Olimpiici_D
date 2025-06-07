#include <bits/stdc++.h>
using namespace std;

pair <int, int> ps[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main () {
    int n, m, ans = 0;
    cin >> n >> m;
    int d2[n + 2][m + 2];
    char s;
    queue <pair<pair<int, int>, int>> bfs;
    for(int r = 0; r <= n + 1; r++) {
        for(int c = 0; c <= m + 1; c++) {
            if(r == 0 || r == n + 1 || c == 0 || c == m + 1) {
                d2[r][c] = 0;
                bfs.push({{r, c}, 0});
            } else {
                cin >> s;
                if(s == '.') d2[r][c] = -1;
                else {
                    d2[r][c] = 0;
                    bfs.push({{r, c}, 0});
                }
            }
        }
    }
    while(!bfs.empty()) {
        pair <int, int> a = bfs.front().first;
        int t = bfs.front().second;
        bfs.pop();
        for(int p = 0; p < 4; p++) {
            int x = a.first + ps[p].first;
            int y = a.second + ps[p].second;
            if(d2[x][y] != -1) continue;
            d2[x][y] = t + 1;
            bfs.push({{x, y}, d2[x][y]});
            ans += d2[x][y];
        }
    }
    cout << ans;

    return 0;
}
