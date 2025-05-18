#include <bits/stdc++.h>
using namespace std;

const int maxc = 12;
char d2[maxc][maxc];
vector <vector<pair<int, int>>> ways;
vector<pair<int, int>> way;

void print (vector <pair<int, int>> res) {
    for(int i = 0; i < res.size(); i++) {
        cout << res[i].first << ':' << res[i].second << ' ';
    }
    cout << '\n';
}

int brw (int bx, int by, int ex, int ey) {
    int ans = 0;
    way.push_back({bx, by});
    if(bx == ex && by == ey) {
        ways.push_back(way);
        return 1;
    }
    if(d2[bx][by] == '#') return 0;
    d2[bx][by] = '#';
    vector<pair<int, int>> help = way;
    ans += brw(bx + 1, by, ex, ey);
    way = help;
    ans += brw(bx, by + 1, ex, ey);
    way = help;
    ans += brw(bx - 1, by, ex, ey);
    way = help;
    ans += brw(bx, by - 1, ex, ey);
    way = help;
    d2[bx][by] = '.';
    return ans;
}

int main () {
    int n, m, x, y, a, b, brp;
    cin >> n >> m;
    for(int r = 0; r <= n + 1; r++) {
        for(int c = 0; c <= m + 1; c++) {
            if(r == 0 || c == 0 || r == n + 1 || c == m + 1) d2[r][c] = '#';
            else cin >> d2[r][c];
            if(d2[r][c] == 'S') {
                x = r;
                y = c;
            }
            if(d2[r][c] == 'F') {
                a = r;
                b = c;
            }
        }
    }
    cout << brw(x, y, a, b) << '\n';
    for(int i = 0; i < ways.size(); i++) {
        print(ways[i]);
    }
    return 0;
}
