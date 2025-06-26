#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * pow(10, 5) + 1;
vector <pair<int, int>> graph[maxn];
bool vis[maxn];

int main () {
    int n, m, k, a, b, t, ans = INT_MAX;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        graph[a].push_back({b, t - 1});
        graph[b].push_back({a, t - 1});
    }
    queue <pair<int, pair<int, int>>> qu;
    qu.push({1, {0, 0}});
    vis[1] = true;
    while(!qu.empty()) {
        int a = qu.front().first, d = qu.front().second.first, pl = qu.front().second.second;
        qu.pop();
        for(auto b : graph[a]) {
            if(vis[b.first]) continue;
            if(b.second == 1 && pl == k) continue;
            vis[b.first] = true;
            qu.push({b.first, {d + 1, pl + b.second}});
            if(b.first == n) ans = min(ans, d + 1);
        }
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}
