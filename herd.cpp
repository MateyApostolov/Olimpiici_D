#include <bits/stdc++.h>
using namespace std;

const int maxc = 252;
char d2[maxc][maxc];
pair<int, int> p[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


int main () {
    int n, m;
    cin >> n >> m;
    vector <pair<int, int>> flood;
    pair<int, int> beg, en;
    for(int r = 0; r < n + 2; r++) {
        for(int c = 0; c < m + 2; c++) {
            if(r == 0 || r == n + 1 || c == 0 || c == m + 1) {
                d2[r][c] = 'X';
                continue;
            }
            cin >> d2[r][c];
            if(d2[r][c] == '*') {
                flood.push_back({r, c});
            }
            if(d2[r][c] == 'S') {
                beg = {r, c};
            }
            if(d2[r][c] == '*') {
                en = {r, c};
            }
        }
    }
    vector <pair<int, int>> bfs;
    for(int k = 0; k < flood.size(); k++) bfs.push_back(flood[k]);
    int t = 1;
    while(!bfs.empty()) {
        vector <pair<int, int>> help;
        for(int i = 0; i < bfs.size(); i++) {
            for(int hp = 0; hp < 4; hp++) {
                int x = bfs[i].first + p[hp].first;
                int y = bfs[i].second + p[hp].second;
                if(d2[x][y] == 'X' || d2[x][y] == '*' || d2[x][y] == 'S' || d2[x][y] == 'D') continue;
                if(d2[x][y] < t) continue;
                d2[x][y] = t;
                help.push_back({x, y});
            }
        }
        t++;
        bfs = help;
    }
    /*for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            if(d2[r][c] == 'X' || d2[r][c] == '*' || d2[r][c] == 'S' || d2[r][c] == 'D') cout << setw(3) << d2[r][c];
            else cout << setw(3) << td2[r][c];
        }
        cout << '\n';
    }*/
    bfs.clear();
    bfs.push_back(beg);
    t = 0;
    while(!bfs.empty()) {
        vector <pair<int, int>> help;
        for(int i = 0; i < bfs.size(); i++) {
            for(int hp = 0; hp < 4; hp++) {
                int x = bfs[i].first + p[hp].first;
                int y = bfs[i].second + p[hp].second;
                if(d2[x][y] == 'D' && d2[bfs[i].first][bfs[i].second] > t) {
                    cout << t + 1;
                    return 0;
                }
                if(d2[x][y] == 'X' || d2[x][y] == '*' || d2[x][y] == 'S' || d2[x][y] == 'D') continue;
                if(d2[x][y] <= t) continue;
                help.push_back({x, y});
                d2[x][y] = 'X';
            }
        }
        t++;
        bfs = help;
    }
    cout << "Impossible";

    return 0;
}
