#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 6) + 1;
vector <long long> graph[maxn];
bool vis[maxn];

int main () {
    long long n, m, a, b, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        queue <int> bfs;
        bfs.push(i);
        vis[i] = true;
        long long brc = 1;
        while(!bfs.empty()) {
            int a = bfs.front();
            bfs.pop();
            vis[a] = true;
            for(auto b : graph[a]) {
                if(vis[b]) continue;
                bfs.push(b);
                brc++;
            }
        }
        ans += (brc * (brc - 1)) / 2;
    }
    ans = (n * (n - 1)) / 2 - ans;
    cout << ans;
    return 0;
}
