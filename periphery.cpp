#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 5);
vector <int> graf[maxn];
bool vis[maxn] = {};
int comp[maxn] = {};

void dfs(int s, int c) {
    vis[s] = true;
    comp[s] = c;
    for(auto x : graf[s]) {
        if(vis[x]) continue;
        dfs(x, c);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, s, t, a, b, q, c = 1;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        dfs(i, c);
        c++;
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> s >> t;
        if(comp[s] != comp[t]) cout << 0;
        else cout << 1;
    }
    return 0;
}
