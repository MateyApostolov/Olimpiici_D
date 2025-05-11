#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 3) + 1;
char d2[maxc][maxc];
int td2[maxc][maxc], pc[maxc][maxc];
pair <int, int> p4[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


int main () {
    int n, m, inx, iny, outx, outy, t = 1;
    char s;
    cin >> n >> m;
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            cin >> s;
            if(s == 'S') {
                inx = r;
                iny = c;
                td2[r][c] = 1;
            }
            if(s == 'T') {
                outx = r;
                outy = c;
            }
            d2[r][c] = s;
        }
    }
    vector <pair<int, int>> curt;
    curt.push_back({inx, iny});
    while(!curt.empty()) {
        t++;
        vector <pair<int, int>> ht;
        for(int i = 0; i < curt.size(); i++) {
            pair <int, int> p = curt[i];
            if(d2[p.first][p.second] == '+') pc[p.first][p.second]++;
            for(int hp = 0; hp < 4; hp++) {
                int px = p.first + p4[hp].first;
                int py = p.second + p4[hp].second;
                if(px <= 0 || px > n || py <= 0 || py > m) continue;
                if(d2[px][py] == 'x') continue;
                if(td2[px][py] == t) {
                    pc[px][py] = max(pc[p.first][p.second], pc[px][py]);
                }
                if(td2[px][py] > 0) continue;
                td2[px][py] = t;
                ht.push_back({px, py});
            }
        }
        curt = ht;
    }
    /*for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            cout << td2[r][c] - 1 << ' ';
        }
        cout << '\n';
    }*/
    cout << td2[outx][outy] - 1 << ' ' << pc[outx][outy];
    return 0;
}
