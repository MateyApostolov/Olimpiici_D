#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 3) + 2;
bool d2[maxn][maxn];
pair<int, int> p[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, w, n, q = 0, x, y, bx, by, qx, qy;
    cin >> h >> w >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        d2[x][y] = true;
    }
    bool t = false;
    for(int p1 = 0; p1 < 3; p1++) {
        for(int p2 = p1 + 1; p2 < 4; p2++) {
            queue <pair<int, int>> qu;
            qu.push({x, y});
            int px, py, br = 0;
            while(!qu.empty()) {
                br++;
                int hx = qu.front().first, hy = qu.front().second;
                qu.pop();
                px = hx + p[p1].first;
                py = hy + p[p1].second;
                if(d2[px][py]) qu.push({px, py});
                px = hx + p[p2].first;
                py = hy + p[p2].second;
                if(d2[px][py]) qu.push({px, py});
            }
            if(br == n) {
                t = true;
                break;
            }
        }
    }
    if(t) cout << "YES\n";
    else cout << "NO\n";
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> qx >> qy;
        d2[qx][qy] = true;
        bool t = false;
        for(int p1 = 0; p1 < 3; p1++) {
            for(int p2 = p1 + 1; p2 < 4; p2++) {
                queue <pair<int, int>> qu;
                qu.push({qx, qy});
                int px, py, br = 0;
                while(!qu.empty()) {
                    br++;
                    int hx = qu.front().first, hy = qu.front().second;
                    qu.pop();
                    px = hx + p[p1].first;
                    py = hy + p[p1].second;
                    if(d2[px][py]) qu.push({px, py});
                    px = hx + p[p2].first;
                    py = hy + p[p2].second;
                    if(d2[px][py]) qu.push({px, py});
                }
                if(br == n + i + 1) {
                    t = true;
                    break;
                }
            }
        }
        if(t) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

