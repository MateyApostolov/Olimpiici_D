#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, a, b;
    cin >> n >> k;
    vector <int> graf[n + 1];
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    bool vis[n + 1] = {};
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        if(graf[i].empty()) continue;
        int brk = 0, brn = 0;
        vis[i] = true;
        queue <int> qu;
        qu.push(i);
        while(!qu.empty()) {
            int help = qu.front();
            qu.pop();
            brk += graf[help].size();
            brn++;
            for(int x = 0; x < graf[help].size(); x++) {
                if(vis[graf[help][x]]) continue;
                vis[graf[help][x]] = true;
                qu.push(graf[help][x]);
            }
        }
        if(brk != brn * (brn - 1)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
