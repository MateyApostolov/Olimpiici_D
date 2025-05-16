#include <bits/stdc++.h>
using namespace std;

const int maxc = 252;
char d2[maxc][maxc];
pair<int, int> p[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


int main () {
    int n, m;
    cin >> n >> m;
    vector <pair<int, int>> flood, bfs;
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
    bfs.push_back(beg);
    int t = 0;
    while(!bfs.empty()) {
        t++;
        vector <pair<int, int>> helpf;
        for(int i = 0; i < flood.size(); i++) {
            for(int hp = 0; hp < 4; hp++) {
                int x = flood[i].first + p[hp].first;
                int y = flood[i].second + p[hp].second;
                if(d2[x][y] == 'X' || d2[x][y] == '*' || d2[x][y] == 'S' || d2[x][y] == 'D') continue;
                d2[x][y] = 'X';
                helpf.push_back({x, y});
            }
        }
        flood = helpf;
        vector <pair<int, int>> help;
        for(int i = 0; i < bfs.size(); i++) {
            for(int hp = 0; hp < 4; hp++) {
                int x = bfs[i].first + p[hp].first;
                int y = bfs[i].second + p[hp].second;
                if(d2[x][y] == 'D') {
                    cout << t + 1;
                    return 0;
                }
                if(d2[x][y] == 'X' || d2[x][y] == '*' || d2[x][y] == 'S' || d2[x][y] == 'D') continue;
                help.push_back({x, y});
                d2[x][y] = 'X';
            }
        }
        bfs = help;
    }
    cout << "Impossible";

    return 0;
}
