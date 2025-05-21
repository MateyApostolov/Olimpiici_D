#include <bits/stdc++.h>
using namespace std;

const int maxc = pow(10, 3) + 2;
int n, m, k, d2[maxc][maxc], mp[maxc][maxc], l, r = pow(10, 9), mid;
pair <int, int> p4[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pair <int, pair<int, int>> kc[maxc * maxc];


bool ok (int d) {
    bool zdr[k] = {}, vis[n + 2][m + 2];
    for(int r = 0; r <= n + 1; r++) {
        for(int c = 0; c <= m + 1; c++) {
            vis[r][c] = 0;
        }
    }
    for(int i = 0; i < k; i++) {
        if(zdr[i]) continue;
        vector <pair<int, int>> curt;
        curt.push_back({kc[i].second.first, kc[i].second.second});
        bool t = true;
        while(!curt.empty()) {
            vector <pair<int, int>> help;
            for(int x = 0; x < curt.size(); x++) {
                for(int p = 0; p < 4; p++) {
                    int px = curt[x].first + p4[p].first;
                    int py = curt[x].second + p4[p].second;
                    if(d2[px][py] == 0) continue;
                    if(vis[px][py]) continue;
                    if(d2[px][py] > kc[i].first + d) continue;
                    if(px == 1 || py == 1 || px == n || py == m) t = false;
                    if(mp[px][py] != 0) zdr[mp[px][py] - 1] = true;
                    vis[px][py] = true;
                    help.push_back({px, py});
                }
            }
            curt = help;
        }
        if(t) return true;
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            cin >> d2[r][c];
        }
    }
    for(int i = 0; i < k; i++) {
        cin >> kc[i].second.first >> kc[i].second.second >> kc[i].first;
    }
    sort(kc, kc + k);
    reverse(kc, kc + k);
    for(int i = 0; i < k; i++) {
        mp[kc[i].second.first][kc[i].second.second] = i + 1;
    }
    while(l < r) {
        mid = (l + r) / 2;
        if(ok(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l;
    return 0;
}
